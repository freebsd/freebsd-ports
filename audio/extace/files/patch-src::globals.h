--- src/globals.h.orig	Sun May 18 20:39:47 2003
+++ src/globals.h	Sun May 18 20:40:01 2003
@@ -255,8 +255,8 @@
 gint 		winstyle;	/* window function options */	
 gint		active_drawing_area;
 gfloat 		noise_floor;
-gfloat 		noise_floor_min;
-gfloat 		noise_floor_max;
+extern const float 		noise_floor_min;
+extern const float 		noise_floor_max;
 gint 		paused;
 gint		low_freq;
 gint		high_freq;
