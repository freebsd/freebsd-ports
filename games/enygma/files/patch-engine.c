--- engine.c.orig	2004-02-29 14:39:00 UTC
+++ engine.c
@@ -181,7 +181,7 @@ gamestate *make_move (gamestate *state, 
      * process teleporters
      */
     if (i == '#') {
-	int x, y;
+	int x, y = 0;
 
 	/*
 	 * First find the other teleporter.
