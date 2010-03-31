--- src/celengine/image.cpp.orig	2009-06-22 17:44:08.000000000 +0200
+++ src/celengine/image.cpp	2010-03-29 14:11:02.000000000 +0200
@@ -737,7 +737,7 @@
 
     if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
     {
-        png_set_gray_1_2_4_to_8(png_ptr);
+        png_set_expand_gray_1_2_4_to_8(png_ptr);
     }
 
     if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
