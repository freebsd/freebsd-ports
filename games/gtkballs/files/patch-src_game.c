--- src/game.c.orig	Wed Oct  6 20:06:46 2004
+++ src/game.c	Wed Oct 27 02:10:30 2004
@@ -495,8 +495,8 @@
                         lock_actions(1);
                         draw_board();
 	                for(animtime = 0, i = 0; i < animcadres;) {
-                        	gettimeofday(&tvs, NULL);
                 	        gint isav = i;
+                        	gettimeofday(&tvs, NULL);
 	                	for(; animtime == animarray[i].time && i < animcadres; i++) {
                         		draw_ball(animarray[i].color, animarray[i].x, animarray[i].y, 0, animarray[i].phase + 1);
                                         _board_destroys[animarray[i].y * rules_get_width() + animarray[i].x] = animarray[i].phase + 1;
