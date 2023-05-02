#include <iostream>
using namespace std;

char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char currentPlayer = 'X';

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMark(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        cout << "Invalid move, please try again." << endl;
        return false;
    }
    if (board[row][col] != ' ') {
        cout << "That spot is already taken, please try again." << endl;
        return false;
    }
    board[row][col] = currentPlayer;
    return true;
}

bool checkForWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }
    return false;
}

bool checkForTie() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    }
    else {
        currentPlayer = 'X';
    }
}

int main() {
    int row, col;
    bool gameOver = false;

    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "Player 1 is X, Player 2 is O." << endl;
    drawBoard();

    while (!gameOver) {
        cout << "Player " << currentPlayer << ", enter row (0-2): ";
        cin >> row;
        cout << "Player " << currentPlayer << ", enter column (0-2): ";
        cin >> col;
        if (placeMark(row, col)) {
            drawBoard();
            if (checkForWin()) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            }
        }
    }
}