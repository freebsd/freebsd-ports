--- plugins/loader/png/png.c.orig	2006-03-12 09:24:16.000000000 +0100
+++ plugins/loader/png/png.c	2010-03-29 16:51:07.000000000 +0200
@@ -156,7 +156,7 @@
   int try_when_error;
   unsigned int i, num_text;
   int num_trans;
-  png_color_16p trans_values;
+  png_color_16p trans_color;
   png_bytep trans;
 
   //debug_message("png loader: load() called\n");
@@ -260,7 +260,7 @@
   color_type = png_get_color_type(png_ptr, info_ptr);
 
   /* Set the transparent color */
-  if (png_get_tRNS(png_ptr, info_ptr, &trans, &num_trans, &trans_values)) {
+  if (png_get_tRNS(png_ptr, info_ptr, &trans, &num_trans, &trans_color)) {
     //p->transparent_disposal = info->transparent_disposal;
     switch (color_type) {
     case PNG_COLOR_TYPE_PALETTE:
@@ -273,13 +273,13 @@
       break;
     case PNG_COLOR_TYPE_RGB:
     case PNG_COLOR_TYPE_RGB_ALPHA:
-      p->transparent_color.red = info_ptr->trans_values.red >> 8;
-      p->transparent_color.green = info_ptr->trans_values.green >> 8;
-      p->transparent_color.blue = info_ptr->trans_values.blue >> 8;
+      p->transparent_color.red = info_ptr->trans_color.red >> 8;
+      p->transparent_color.green = info_ptr->trans_color.green >> 8;
+      p->transparent_color.blue = info_ptr->trans_color.blue >> 8;
       break;
     case PNG_COLOR_TYPE_GRAY:
     case PNG_COLOR_TYPE_GRAY_ALPHA:
-      p->transparent_color.gray = info_ptr->trans_values.gray;
+      p->transparent_color.gray = info_ptr->trans_color.gray;
       break;
     default:
       break;
