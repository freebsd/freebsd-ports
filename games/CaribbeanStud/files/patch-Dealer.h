--- ./Dealer.h.orig	2013-10-29 15:12:13.000000000 -0200
+++ ./Dealer.h	2013-10-29 15:12:13.000000000 -0200
@@ -92,7 +92,8 @@
 
 inline void Dealer::Add    (Player* newPlayer)
 {
-   for(int i=0; i < 10; i++)
+   int i;
+   for(i=0; i < 10; i++)
       if( !_players[i] ){
 			_players[i] = newPlayer;
          break;
@@ -102,8 +103,8 @@
 
 inline void Dealer::Remove (Player* aplayer)
 {
-   int pos = 20;
-	for(int i=0; _players[i]; i++)
+   int pos = 20, i;
+	for(i=0; _players[i]; i++)
 		if(aplayer == _players[i])
 		{
 			pos = i; break;
