--- Dealer.cpp.orig	Tue Aug 19 12:01:24 2003
+++ Dealer.cpp	Tue Aug 19 12:02:07 2003
@@ -141,7 +141,8 @@
 
 void Dealer::NewGame()
 {
-	for(int i=0; _players[i]; i++)
+	int i;
+	for(i=0; _players[i]; i++)
 		_players[i]->NewGame();
 
 	Hands::NewGame();
