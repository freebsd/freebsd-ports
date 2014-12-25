--- lib/EZ_Png.c.orig	1999-12-03 21:49:22 UTC
+++ lib/EZ_Png.c
@@ -61,14 +61,14 @@ static int EZ_ReadPng(fname, w_ret, h_re
       fclose(fp);
       return(0);
     }
-  if(setjmp(png_ptr->jmpbuf))
+  if(setjmp(png_jmpbuf(png_ptr)))
     {
       fclose(fp);
       png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
       return(0);
     }
   
-  if(info_ptr->color_type == PNG_COLOR_TYPE_RGB_ALPHA)
+  if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB_ALPHA)
     {
       png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
       return(0);
@@ -77,15 +77,22 @@ static int EZ_ReadPng(fname, w_ret, h_re
   png_read_info(png_ptr, info_ptr);  /* header */
   png_get_IHDR(png_ptr, info_ptr, &w, &h, &bit_depth, &color_type, &interlace_type, NULL, NULL);
 
-  if(info_ptr->bit_depth < 8) png_set_packing(png_ptr);
+  if(png_get_bit_depth(png_ptr, info_ptr) < 8) png_set_packing(png_ptr);
   if(png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))   png_set_expand(png_ptr);
    png_set_filler(png_ptr, 0xff, PNG_FILLER_AFTER);
 
-   if(info_ptr->valid & PNG_INFO_gAMA)  png_set_gamma(png_ptr, 2.2, info_ptr->gamma);
+   if(png_get_valid(png_ptr, info_ptr, PNG_INFO_gAMA)) {
+	   double gamma;
+	   png_get_gAMA(png_ptr, info_ptr, &gamma);
+	   png_set_gamma(png_ptr, 2.2, gamma);
+   }
    else  png_set_gamma(png_ptr, 2.2, 0.45);
 
-  if(info_ptr->valid & PNG_INFO_bKGD)
-    png_set_background(png_ptr, &info_ptr->background, PNG_BACKGROUND_GAMMA_FILE, 1, 1.0);
+  if(png_get_valid(png_ptr, info_ptr, PNG_INFO_bKGD)) {
+    png_color_16 my_background;
+    png_get_bKGD(png_ptr, info_ptr, &my_background);
+    png_set_background(png_ptr, &my_background, PNG_BACKGROUND_GAMMA_FILE, 1, 1.0);
+    }
   else 
     {
       png_color_16 my_background;
@@ -93,9 +100,9 @@ static int EZ_ReadPng(fname, w_ret, h_re
       png_set_background(png_ptr, &my_background, PNG_BACKGROUND_GAMMA_SCREEN, 0, 2.2);
     }
 
-   if(info_ptr->bit_depth == 16) png_set_strip_16(png_ptr);
+   if(png_get_bit_depth(png_ptr, info_ptr) == 16) png_set_strip_16(png_ptr);
 
-   if(info_ptr->color_type == PNG_COLOR_TYPE_GRAY || info_ptr->color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
+   if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY || png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA)
      png_set_expand(png_ptr);
      
    if((data = (unsigned char *)my_malloc( 4 * w * (h+1)* sizeof(unsigned char), _PNG_IMAGE_)) == NULL)
