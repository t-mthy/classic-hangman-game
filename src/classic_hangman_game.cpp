/*==============================================================================
Module: Categorized Hangman Game

Author: t-mthy

Description: User selects a category in main menu. Try to guess the 
secret word before running out of guesses.
==============================================================================*/


#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<string> game_category(int userChoice);
void in_game_graphics(int badGuess);
void game_intro();
void game_win();
void game_lose();

int main()
{
    string CLS = "\033[2J\033[1;1H";
    string DEFAULT = "\033[0m";
    string YELLOW = "\033[33;1m";
    string GREEN = "\033[32;1m";
    string RED = "\033[31;1m";
    string CYAN = "\033[36;1m";
    string PURPLE = "\033[35;1m";
    
    cout << CLS << CYAN;
    game_intro();
    cout << DEFAULT << "\t\t\t\t\t\t\t\t\t\tby t-mthy" << PURPLE;
    int userNum = 0;
    cout << "\n\n\nSelect a topic to continue...\n";
    cout << "1) National capitals (game format: city, country)\n";
    cout << "2) Company slogans\n";
    cout << "3) Unusual pets\n";
    while (userNum != 1 && userNum != 2 && userNum != 3)
    {
        cout << "\n\nEnter a number for your topic: ";
        cin >> userNum;
        if (userNum != 1 && userNum != 2 && userNum != 3)
            cout << "Invalid Entry. Please enter a given number...";
    }
    
    srand(time(NULL));
    int randNum = rand() % 10;
    vector<string> vecSecretWord = game_category(userNum);
    string secretWord = vecSecretWord[randNum];

    string guessWord = secretWord;
    for (int i = 0; i < secretWord.size(); i++)
    {
        if (secretWord[i] == ' ')
            guessWord[i] = ' ';
        else if (secretWord[i] == ',')
            guessWord[i] = ',';
        else
            guessWord[i] = '-';
    }
    
    int badGuess = 0;
    int location, gussedVal;
    string letter;
    string letterRem = "a b c d e f g h i j k l m n o p q r s t u v w x y z";

    while (badGuess < 6 && guessWord != secretWord)
    {
        cout << CLS << YELLOW;
        in_game_graphics(badGuess);
        cout << DEFAULT;

        cout << "\n\nRemaining letters:\t" << letterRem << endl;
        
        cout << "\n\nYour guess:\t\t" << guessWord << endl;

        cout << "\nEnter a letter to guess: ";
        cin >> letter;
        letter[0] = tolower(letter[0]);
        gussedVal = letterRem.find(letter, 0);
        if (gussedVal != -1)
            letterRem.replace(gussedVal, 1, " ");

        location = secretWord.find(letter, 0);
        if (location == -1)
            badGuess++;
        else
            while (location != -1)
            {
                guessWord.replace(location, 1, letter);
                location = secretWord.find(letter, ++location);
            }
    }
    
    cout << CLS;
    if (guessWord == secretWord)
    {
        cout << GREEN;
        game_win();
        cout << DEFAULT << "\n\n\nCongratulations! You've guessed the phrase: ";
        cout << PURPLE << secretWord << DEFAULT << "\n\n\n\n\n";
    }
    else
    {
        cout << RED;
        game_lose();
        cout << DEFAULT << "\n\n\nBetter luck next time.\n\n\n\n\n";
    }

    return 0;
}

void game_intro()
{
    cout << "\n\n";
    cout << "  _____ _             ____ _               _                                 \n";
    cout << " |_   _| |__   ___   / ___| | __ _ ___ ___(_) ___                            \n";
    cout << "   | | | '_ \\ / _ \\ | |   | |/ _` / __/ __| |/ __|                           \n";
    cout << "   | | | | | |  __/ | |___| | (_| \\__ \\__ \\ | (__                            \n";
    cout << "  _|_|_|_| |_|\\___|  \\____|_|\\__,_|___/___/_|\\___| ____                      \n";
    cout << " | | | | __ _ _ __   __ _ _ __ ___   __ _ _ __    / ___| __ _ _ __ ___   ___ \n";
    cout << " | |_| |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\  | |  _ / _` | '_ ` _ \\ / _ \\\n";
    cout << " |  _  | (_| | | | | (_| | | | | | | (_| | | | | | |_| | (_| | | | | | |  __/\n";
    cout << " |_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|  \\____|\\__,_|_| |_| |_|\\___|\n";
    cout << "                    |___/                                                    \n";
}

void game_win()
{
    cout << "\n\n";
    cout << "  ___    ___ ________  ___  ___          ___       __   ___  ________   ___       \n";
    cout << " |\\  \\  /  /|\\   __  \\|\\  \\|\\  \\        |\\  \\     |\\  \\|\\  \\|\\   ___  \\|\\  \\      \n";
    cout << " \\ \\  \\/  / | \\  \\|\\  \\ \\  \\\\\\  \\       \\ \\  \\    \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\     \n";
    cout << "  \\ \\    / / \\ \\  \\\\\\  \\ \\  \\\\\\  \\       \\ \\  \\  __\\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\    \n";
    cout << "   \\/  /  /   \\ \\  \\\\\\  \\ \\  \\\\\\  \\       \\ \\  \\|\\__\\_\\  \\ \\  \\ \\  \\\\ \\  \\ \\__\\   \n";
    cout << " __/  / /      \\ \\_______\\ \\_______\\       \\ \\____________\\ \\__\\ \\__\\\\ \\__\\|__|   \n";
    cout << "|\\___/ /        \\|_______|\\|_______|        \\|____________|\\|__|\\|__| \\|__|   ___ \n";
    cout << "\\|___|/                                                                      |\\__\\\n";
    cout << "                                                                             \\|__|\n";
    cout << "\n\t\t\t\t\t\\O/\n\t\t\t\t\t |\n\t\t\t\t\t/ \\\n";
}

void game_lose()
{
    cout << "\n\n";
    cout << "    _____      ____       __    __      _____        ____     __    __    _____   ______    \n";
    cout << "   / ___ \\    (    )      \\ \\  / /     / ___/       / __ \\    ) )  ( (   / ___/  (   __ \\   \n";
    cout << "  / /   \\_)   / /\\ \\      () \\/ ()    ( (__        / /  \\ \\  ( (    ) ) ( (__     ) (__) )  \n";
    cout << " ( (  ____   ( (__) )     / _  _ \\     ) __)      ( ()  () )  \\ \\  / /   ) __)   (    __/   \n";
    cout << " ( ( (__  )   )    (     / / \\/ \\ \\   ( (         ( ()  () )   \\ \\/ /   ( (       ) \\ \\  _  \n";
    cout << "  \\ \\__/ /   /  /\\  \\   /_/      \\_\\   \\ \\___      \\ \\__/ /     \\  /     \\ \\___  ( ( \\ \\_)) \n";
    cout << "   \\____/   /__(  )__\\ (/          \\)   \\____\\      \\____/       \\/       \\____\\  )_) \\__/  \n";
    cout << "\n\n\t\t\t\t\t  +----+\n\t\t\t\t\t  |    }\n\t\t\t\t\t  |    O\n\t\t\t\t\t  |   /|\\";
    cout << "\n\t\t\t\t\t  |   / \\\n\t\t\t\t\t  |\n\t\t\t\t\t===========\n";
}

void in_game_graphics(int badGuess)
{
    switch (badGuess)
    {
    case 0:
        cout << "\n  +----+\n  |    }\n  |\n  |\n  |\n  |\n===========\n";
        break;
    case 1:
        cout << "\n  +----+\n  |    }\n  |    O\n  |\n  |\n  |\n===========\n";
        break;
    case 2:
        cout << "\n  +----+\n  |    }\n  |    O\n  |    |\n  |\n  |\n===========\n";
        break;
    case 3:
        cout << "\n  +----+\n  |    }\n  |    O\n  |   /|\n  |\n  |\n===========\n";
        break;
    case 4:
        cout << "\n  +----+\n  |    }\n  |    O\n  |   /|\\\n  |\n  |\n===========\n";
        break;
    case 5:
        cout << "\n  +----+\n  |    }\n  |    O\n  |   /|\\\n  |   /\n  |\n===========\n";
        break;
    default:
        break;
    }
}

vector<string> game_category(int userChoice)
{
    vector<string> guessCategory;

    switch (userChoice)
    {
    case 1:
        guessCategory = {"helsinki, finland", "bogota, colombia", "ottawa, canada",
                        "cairo, egypt", "canberra, australia", "tokyo, japan",
                        "paris, france", "jerusalem, israel", "nuuk, greenland",
                        "reykjavik, iceland"};
        break;
    case 2:
        guessCategory = {"just do it", "that was easy", "think different",
                        "have it your way", "eat mor chikin", "red bull gives you wings",
                        "america runs on dunkin", "go further", "eat fresh",
                        "melts in your mouth, not in your hands"};
        break;
    case 3:
        guessCategory = {"sugar glider", "capybara", "axolotl",
                        "chinchilla", "hedgehog", "fennec fox",
                        "alpaca", "anteater", "ball python",
                        "alligator"};
        break;
    default:
        break;
    }

    return guessCategory;
}
