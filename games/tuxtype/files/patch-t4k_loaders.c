--- ../t4k_common/src/t4k_loaders.c.orig	2011-04-08 11:46:07.000000000 +0900
+++ ../t4k_common/src/t4k_loaders.c	2012-06-17 18:57:09.000000000 +0900
@@ -1028,12 +1028,9 @@
       {
         png_init_io(png_ptr, fi);
 
-        info_ptr->width = surf->w;
-        info_ptr->height = surf->h;
-        info_ptr->bit_depth = 8;
-        info_ptr->color_type = PNG_COLOR_TYPE_RGB_ALPHA;
-        info_ptr->interlace_type = 1;
-        info_ptr->valid = 0;	/* will be updated by various png_set_FOO() functions */
+        png_set_IHDR(png_ptr, info_ptr, surf->w, surf->h, 8,
+                       PNG_COLOR_TYPE_RGB_ALPHA, 1,
+                       PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
 
         png_set_sRGB_gAMA_and_cHRM(png_ptr, info_ptr,
                        PNG_sRGB_INTENT_PERCEPTUAL);
