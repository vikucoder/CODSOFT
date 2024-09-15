#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void placeOnBoard(char player,vector<char>&gameboard){
    int cNumber;
    while(true){
        cout<<player<<"  Choose a number from 1 to 9: ";
        cin>>cNumber;
        if(cNumber>=1&&cNumber<=9&&gameboard[cNumber-1]!='X'&&gameboard[cNumber-1]!='O'){
            break;
        }
        cout<<"Invalid input or spot already marked. Choose another number."<<endl;
    }
    gameboard[cNumber-1]=player;
    cout<<"-------------"<<endl;
    for(int i=0;i<9;i+=3){
        cout<<"| "<<gameboard[i]<<" | "<<gameboard[i+1]<<" | "<<gameboard[i+2]<<" | "<<endl;
        cout<<"-------------"<<endl;
    }
}
bool checkWin(const vector<char>&gameboard,char m){
    for(int i=0;i<9;i+=3){
        if(gameboard[i]==m&&gameboard[i+1]==m&&gameboard[i+2]==m){
            return true;
        }
    }
    for(int i=0;i<3;i++){
        if(gameboard[i]==m&&gameboard[i+3]==m&&gameboard[i+6]==m){
            return true;
        }
    }
    if((gameboard[0]==m&&gameboard[4]==m&&gameboard[6]==m)||(gameboard[2]==m&&gameboard[4]==m&&gameboard[6]==m)){
        return true;
    }
    return false;
}
bool checkDraw(const vector<char>&gameboard){
    for(char m:gameboard){
        if(m!='X'&&m!='O'){
            return false;
        }
    }
    cout<<"We have a draw!! Thank you for playing."<<endl;
    return true;
}
int main(){
    cout<<"* Tic-Tac-Toe Game *"<<endl;
    while(true){
        vector<string>players;
        string player1;
        cout<<"Name of player 1: ";
        cin>>player1;
        players.push_back(player1);
        string player2;
        cout<<"Name of player 2: ";
        cin>>player2;
        players.push_back(player2);
        vector<char>m={'X','O'};
        vector<char>gameboard(9,' ');
        cout<<"These are the players: "<<players[0]<<" and "<<players[1]<<endl;
        cout<<"These are their markers: "<<m[0]<<" and "<<m[1]<<endl;
        cout<<"The game board looks like this:"<<endl;
        cout<<"-------------"<<endl;
        for(int i=0;i<9;i+=3){
            cout<<"| "<<i+1<<" | "<<i+2<<" | "<<i+3<<" | "<<endl;
            cout<<"-------------"<<endl;
        }
        while(true){
            placeOnBoard(m[0],gameboard);
            if(checkWin(gameboard,m[0])){
                cout<<"We have a winner!! Congratulations "<<players[0]<<"!!"<<endl;
                break;
            }
            if(checkDraw(gameboard)){
                break;
            }
            placeOnBoard(m[1],gameboard);
            if(checkWin(gameboard,m[1])){
                cout<<"We have a winner!! Congratulations "<<players[1]<<"!!"<<endl;
                break;
            }
            if(checkDraw(gameboard)){
                break;
            }
        }
        char playagain;
        cout<<"Do you want to  play another game? (y/n): ";
        cin>>playagain;
        if(playagain!='y'&&playagain!='Y'){
            break;
        }
    }
    return 0;
}