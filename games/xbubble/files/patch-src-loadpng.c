$OpenBSD: patch-src_loadpng_c,v 1.1 2011/07/08 20:38:01 naddy Exp $

Fix build with png-1.5.

--- src/loadpng.c.orig	Wed Jul  6 15:26:00 2011
+++ src/loadpng.c	Wed Jul  6 15:28:42 2011
@@ -73,7 +73,7 @@ unsigned char * load_png_file( const char *file, 
     return NULL;
   }
   /* libpng does a longjmp here when it encounters an error */
-  if ( setjmp( png_ptr->jmpbuf ) ) {
+  if ( setjmp( png_jmpbuf( png_ptr ) ) ) {
     png_destroy_read_struct( &png_ptr, &info_ptr, NULL);
     fclose(fd);
     return NULL;
@@ -95,7 +95,7 @@ unsigned char * load_png_file( const char *file, 
     png_set_gray_to_rgb(png_ptr);
 
   /* detect alpha layer */
-  if (( info_ptr->color_type & PNG_COLOR_MASK_ALPHA )||
+  if (( png_get_color_type ( png_ptr, info_ptr ) & PNG_COLOR_MASK_ALPHA )||
       ( png_get_valid( png_ptr, info_ptr, PNG_INFO_tRNS )))
     *has_alpha = 1;
   else
