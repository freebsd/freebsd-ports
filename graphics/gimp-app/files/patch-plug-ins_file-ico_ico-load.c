--- plug-ins/file-ico/ico-load.c.orig	2010-03-28 14:29:48.000000000 +0200
+++ plug-ins/file-ico/ico-load.c	2010-03-28 14:31:00.000000000 +0200
@@ -287,14 +287,14 @@
   switch (color_type)
     {
     case PNG_COLOR_TYPE_GRAY:
-      png_set_gray_1_2_4_to_8 (png_ptr);
+      png_set_expand_gray_1_2_4_to_8 (png_ptr);
       if ( bit_depth == 16 )
         png_set_strip_16 (png_ptr);
       png_set_gray_to_rgb (png_ptr);
       png_set_add_alpha (png_ptr, 0xff, PNG_FILLER_AFTER);
       break;
     case PNG_COLOR_TYPE_GRAY_ALPHA:
-      png_set_gray_1_2_4_to_8 (png_ptr);
+      png_set_expand_gray_1_2_4_to_8 (png_ptr);
       if ( bit_depth == 16 )
         png_set_strip_16 (png_ptr);
       png_set_gray_to_rgb (png_ptr);
