--- ui/svga/svgadisplay.c.orig	2007-07-29 14:53:05.000000000 +0200
+++ ui/svga/svgadisplay.c	2007-07-29 14:53:45.000000000 +0200
@@ -258,7 +258,7 @@
   scaled_x = scale * x; scaled_y = scale * y;
 
   /* Create scaled image */
-  scaler_proc16( (libspectrum_byte*)&svgadisplay_image[y][x], display_pitch,
+  scaler_proc16( (libspectrum_byte*)&svgadisplay_image[y][x], svgadisplay_pitch,
 		 (libspectrum_byte*)&scaled_image[scaled_y][scaled_x],
 		 scaled_pitch, w, h );
 
