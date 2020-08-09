# include <iostream>
# include <string>

using namespace std;

int main() {

    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    string secret_message;

    cout << "Enter your secret message: ";
    getline(cin, secret_message);
    cout << endl;

    string encrypted_message;
    cout << "Encrypting..." << endl;

    //loops through secret_message and replaces the charcters in encrypted_message
    for (char c: secret_message) {
        size_t pos = alphabet.find(c);
            if (pos != string::npos) {
                char new_char {key.at(pos)};
                encrypted_message += new_char;
            } else {
                encrypted_message += c;
            }
    }

    cout << "Your Encrypted message is: " + encrypted_message << endl;
    cout << endl;

    char choice;
    cout << "Would you like to decrypt a message? [Y/N]: ";
    cin >> choice;

    string decrypted_message {};
    string encrypted_input;
    switch (choice) {
        case 'y':
        case 'Y':
            cin.clear();
            cin.sync();
            cout << "Enter your encrypted message: ";
            getline(cin, encrypted_input);
            cout << endl;

            cout << "Decrypting..." << endl;

            //loops through encrypted_input and replaces the characters to make the decrypted_message
            for (char c: encrypted_input) {
                size_t pos = key.find(c);
                if (pos != string::npos) {
                    char new_char {alphabet.at(pos)};
                    decrypted_message += new_char;
                } else {
                    decrypted_message += c;
                }
            }

            cout << "Your decrypted message is: " + decrypted_message << endl;
            break;
        case 'n':
        case 'N':
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Unknown selection. Exiting program." << endl;
            break;
    }

    return 0;
}