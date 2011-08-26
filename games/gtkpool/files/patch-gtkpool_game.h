--- gtkpool/game.h.orig	2002-07-29 10:02:15.000000000 +0900
+++ gtkpool/game.h	2011-08-19 04:36:48.000000000 +0900
@@ -19,10 +19,7 @@
 #define GAME_H
 #include <gtk/gtk.h>
 #include <vector>
-#include "ball.h"
-#include "check_pocket.h"
-#include "move_balls.h"
-#include "moving.h"
+#include <cstring>
 
 /**
   *@author Brian Ashe
@@ -31,10 +28,12 @@
 class check_pocket;
 
 enum turns { tplayer1, tplayer2 };				// Tell whose turn it is on
-enum catagories { stripes, solids, other };				// What are they shooting at
+enum categories { stripes, solids, other };				// What are they shooting at
 enum player_types { human, computer, remote };	// What type of player (future use)
 enum game_types { eight_ball, nine_ball, rotation, snooker, continuous14_1, no_rules };
 
+#include "ball.h"
+
 struct player {
 	char player_name [30];		// Player's name
 	int category;				// Stripes or solids
@@ -74,3 +73,4 @@
 };
 
 #endif
+
