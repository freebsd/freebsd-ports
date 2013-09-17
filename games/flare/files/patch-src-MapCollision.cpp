--- src/MapCollision.cpp.orig	2013-04-01 18:21:13.000000000 +0400
+++ src/MapCollision.cpp	2013-09-17 06:00:27.655226476 +0400
@@ -238,7 +238,7 @@
 		for (int i=0; i<steps; i++) {
 			x += step_x;
 			y += step_y;
-			if (is_wall(round(x), round(y)))
+			if (is_wall(myround(x), myround(y)))
 				return false;
 		}
 	}
@@ -246,7 +246,7 @@
 		for (int i=0; i<steps; i++) {
 			x += step_x;
 			y += step_y;
-			if (!is_valid_position(round(x), round(y), movement_type))
+			if (!is_valid_position(myround(x), myround(y), movement_type))
 				return false;
 		}
 	}
