
$FreeBSD$

--- proto_xboard.cc.orig	Mon Jun 17 05:24:31 2002
+++ proto_xboard.cc	Sat Sep 28 23:00:58 2002
@@ -267,7 +267,7 @@
 }
 
 void XBoardProtocol::gameOver(ExtPatternMatcher &pm,GameResult gr,
-                                    int hasreason=1)
+                                    int hasreason)
 {
   char reason[64];
   ChessGame *refgame;  
