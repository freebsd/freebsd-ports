--- converter/ppm/ppmtompeg/jpeg.c.orig	2005-11-10 04:53:40.000000000 +0100
+++ converter/ppm/ppmtompeg/jpeg.c	2009-07-07 10:51:13.000000000 +0200
@@ -469,7 +469,7 @@
 #ifdef JPEG4
     buffer_height = 8;  /* could be 2, 4,8 rows high */
 #else
-    buffer_height = cinfo.max_v_samp_factor * cinfo.min_DCT_scaled_size;
+    buffer_height = cinfo.max_v_samp_factor * cinfo.min_DCT_v_scaled_size;
 #endif
   
     for(cp=0,compptr = cinfo.comp_info;cp<cinfo.num_components;
