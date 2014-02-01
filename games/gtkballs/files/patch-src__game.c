--- ./src/game.c.orig	2004-10-06 13:06:46.000000000 +0200
+++ ./src/game.c	2014-02-01 20:44:28.000000000 +0100
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
