--- src/boss.c.orig	2008-01-15 05:54:37.000000000 +0300
+++ src/boss.c	2008-12-01 02:19:45.000000000 +0300
@@ -691,7 +691,7 @@
 			} else {
 				if (dist(tail_x[0], tail_y[0], boss_x, boss_y) >= 24) {
 					if (boss_tail_len < 10) boss_tail_len++;
-					for (i = 9; i >= 0; i--) {
+					for (i = 8; i >= 0; i--) {
 						tail_x[i+1] = tail_x[i];
 						tail_y[i+1] = tail_y[i];
 					}
