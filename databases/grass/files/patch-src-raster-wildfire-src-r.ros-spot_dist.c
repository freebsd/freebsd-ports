--- src/raster/wildfire/src/r.ros/spot_dist.c.orig	Sun Jul 11 17:41:42 2004
+++ src/raster/wildfire/src/r.ros/spot_dist.c	Sun Jul 11 17:42:04 2004
@@ -119,7 +119,7 @@
 
 		if (DATA(map_elev,row,col) > z) {
 #ifdef DEBUG
-printf ("\nA return: m%d U=%d(m/h) h0=%d(m) e0(%d,%d)=%d z=%d(m) e(%d,%d)=%d 
+printf ("\nA return: m%d U=%d(m/h) h0=%d(m) e0(%d,%d)=%d z=%d(m) e(%d,%d)=%d\ 
 s=%d(m)", (int)fuel, (int)U, (int)h0, row0,col0,DATA(map_elev,row0,col0), 
 (int)z, row,col,DATA(map_elev,row,col), S);
 #endif
