--- src/game.c.orig	2015-03-09 12:48:31 UTC
+++ src/game.c
@@ -23,6 +23,10 @@
 #include "menu.h"
 #include "sys.h"
 
+bool cursor_moving;
+int cursor_timer;
+int rebind_index;
+
 void gameTitle() {
     title_screen = true;
     high_scores_screen = false;
