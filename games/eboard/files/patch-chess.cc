
$FreeBSD$

--- chess.cc.orig	Sat Jun 22 20:42:42 2002
+++ chess.cc	Sat Sep 28 23:00:58 2002
@@ -257,7 +257,7 @@
 
 void ChessGame::updatePosition(Position &p,int movenum,int blacktomove,
 			       int wclock,int bclock,char *infoline, 
-			       bool sndflag=false) {
+			       bool sndflag) {
   char z[32];
 
   global.debug("ChessGame","updatePosition");
@@ -738,7 +738,7 @@
     pgn.set("FEN", moves.front().getFEN() );
 }
 
-bool ChessGame::savePGN(char *filename, bool append=false) {
+bool ChessGame::savePGN(char *filename, bool append) {
   char z[512];
   const char *cp;
   list<Position>::iterator li;
@@ -827,8 +827,8 @@
 			     char * filename,
 			     bool indexonly, 
 			     int gameid,
-			     variant v = REGULAR,
-			     ChessGame *updatee = NULL) {
+			     variant v,
+			     ChessGame *updatee) {
   /* 
      ok, now (0.4.x) we do this in a DFA-like manner
      0  = state 0 (whitespace before movetext)
