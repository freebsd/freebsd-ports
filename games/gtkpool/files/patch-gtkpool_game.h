--- gtkpool/game.h.orig	Mon Aug  1 17:17:05 2005
+++ gtkpool/game.h	Mon Aug  1 17:17:41 2005
@@ -19,10 +19,6 @@
 #define GAME_H
 #include <gtk/gtk.h>
 #include <vector>
-#include "ball.h"
-#include "check_pocket.h"
-#include "move_balls.h"
-#include "moving.h"
 
 /**
   *@author Brian Ashe
@@ -34,6 +30,11 @@
 enum catagories { stripes, solids, other };				// What are they shooting at
 enum player_types { human, computer, remote };	// What type of player (future use)
 enum game_types { eight_ball, nine_ball, rotation, snooker, continuous14_1, no_rules };
+
+#include "ball.h"
+#include "check_pocket.h"
+#include "move_balls.h"
+#include "moving.h"
 
 struct player {
 	char player_name [30];		// Player's name
