--- converter/ppm/ppmtompeg/jpeg.c.orig	2002-10-17 16:49:49.000000000 +0200
+++ converter/ppm/ppmtompeg/jpeg.c	2009-07-07 09:29:29.000000000 +0200
@@ -481,7 +481,7 @@
 #ifdef JPEG4
   buffer_height = 8;  /* could be 2, 4,8 rows high */
 #else
-  buffer_height = cinfo.max_v_samp_factor * cinfo.min_DCT_scaled_size;
+  buffer_height = cinfo.max_v_samp_factor * cinfo.min_DCT_v_scaled_size;
 #endif
   
   for(cp=0,compptr = cinfo.comp_info;cp<cinfo.num_components;
