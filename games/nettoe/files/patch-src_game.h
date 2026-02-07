--- src/game.h.orig	2014-03-21 08:38:58 UTC
+++ src/game.h
@@ -43,8 +43,8 @@
 
 #define MAX_PNAME_LEN 32 /* this define max chars for the player names*/
 
-int NO_BEEP;
+extern int NO_BEEP;
 
-int NO_COLORS;
+extern int NO_COLORS;
 
-int addrfamily;
+extern int addrfamily;
