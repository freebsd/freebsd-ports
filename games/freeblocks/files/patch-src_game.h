--- src/game.h.orig	2015-03-09 12:48:31 UTC
+++ src/game.h
@@ -21,9 +21,9 @@
 
 #include "sys.h"
 
-bool cursor_moving;
-int cursor_timer;
-int rebind_index;
+extern bool cursor_moving;
+extern int cursor_timer;
+extern int rebind_index;
 
 void gameTitle();
 void gameHighScores();
