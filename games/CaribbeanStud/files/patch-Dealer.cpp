--- ./Dealer.cpp.orig	2013-10-29 15:12:13.000000000 -0200
+++ ./Dealer.cpp	2013-10-29 15:12:13.000000000 -0200
@@ -28,6 +28,8 @@
 #include "Dealer.h"
 #include "Player.h"
 
+using namespace std;
+
 Dealer::Dealer( Seat * dealerSeat ) : _seat(dealerSeat), _current(0)
 {
    _minjackPot = 2000000;
@@ -141,7 +143,8 @@
 
 void Dealer::NewGame()
 {
-	for(int i=0; _players[i]; i++)
+	int i;
+	for(i=0; _players[i]; i++)
 		_players[i]->NewGame();
 
 	Hands::NewGame();
