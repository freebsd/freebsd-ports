--- src/game.c.orig	2004-10-06 11:06:46 UTC
+++ src/game.c
@@ -406,7 +406,8 @@ gint game_destroy_lines(gboolean count_s
 					for(i = 1;
  					    i < rules_get_width() - x &&
                                 	    board_get_at_xy(x + i, y) == board_get_at_xy(x, y);
-	 				    i++);
+	 				    i++)
+	 				    ;
         				if(i >= rules_get_destroy()) {
                                                 have_del = 1;
                         	                for(j = 0; j < i; j ++) {
@@ -419,7 +420,8 @@ gint game_destroy_lines(gboolean count_s
                                 	for(i = 1;
 					    i < rules_get_height() - y &&
         	                            board_get_at_xy(x, y + i) == board_get_at_xy(x, y);
-                	                    i++);
+                	                    i++)
+                	                    ;
                         	        if(i >= rules_get_destroy()) {
                                                 have_del = 1;
                                         	for(j = 0; j < i; j ++) {
@@ -434,7 +436,8 @@ gint game_destroy_lines(gboolean count_s
  					    i < rules_get_width() - x &&
  					    i < rules_get_height() - y &&
 	                                    board_get_at_xy(x + i, y + i) == board_get_at_xy(x, y);
- 					    i++);
+ 					    i++)
+ 					    ;
         				if(i >= rules_get_destroy()) {
                                                 have_del = 1;
                                 	        for(j = 0; j < i; j ++) {
@@ -449,7 +452,8 @@ gint game_destroy_lines(gboolean count_s
  					    i <= x &&
  					    i < rules_get_height() - y &&
 	                                    board_get_at_xy(x - i, y + i) == board_get_at_xy(x, y);
- 					    i++);
+ 					    i++)
+ 					    ;
         				if(i >= rules_get_destroy()) {
                                                 have_del = 1;
                                 	        for(j = 0; j < i; j ++) {
@@ -495,8 +499,8 @@ gint game_destroy_lines(gboolean count_s
                         lock_actions(1);
                         draw_board();
 	                for(animtime = 0, i = 0; i < animcadres;) {
-                        	gettimeofday(&tvs, NULL);
                 	        gint isav = i;
+                        	gettimeofday(&tvs, NULL);
 	                	for(; animtime == animarray[i].time && i < animcadres; i++) {
                         		draw_ball(animarray[i].color, animarray[i].x, animarray[i].y, 0, animarray[i].phase + 1);
                                         _board_destroys[animarray[i].y * rules_get_width() + animarray[i].x] = animarray[i].phase + 1;
