--- CImg.h.orig	2009-05-26 18:27:28.000000000 +0200
+++ CImg.h	2010-03-29 18:04:12.000000000 +0200
@@ -30161,7 +30161,7 @@
       png_read_info(png_ptr,info_ptr);
       png_uint_32 W, H;
       int bit_depth, color_type, interlace_type;
-      png_get_IHDR(png_ptr,info_ptr,&W,&H,&bit_depth,&color_type,&interlace_type,int_p_NULL,int_p_NULL);
+      png_get_IHDR(png_ptr,info_ptr,&W,&H,&bit_depth,&color_type,&interlace_type,NULL,NULL);
       int new_bit_depth = bit_depth;
       int new_color_type = color_type;
 
@@ -30172,7 +30172,7 @@
         new_bit_depth = 8;
       }
       if (new_color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8){
-        png_set_gray_1_2_4_to_8(png_ptr);
+        png_set_expand_gray_1_2_4_to_8(png_ptr);
         new_bit_depth = 8;
       }
       if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
