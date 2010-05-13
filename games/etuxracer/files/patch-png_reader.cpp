--- src/ppgltk/images/png_reader.cpp.old	2010-05-13 03:10:43.000000000 -0500
+++ src/ppgltk/images/png_reader.cpp	2010-05-13 03:11:44.000000000 -0500
@@ -77,7 +77,7 @@
 	
 	
 	png_get_IHDR(png_ptr, info_ptr, &width, &height,
-       &bit_depth, &color_type, &interlace_type,int_p_NULL, int_p_NULL);
+       &bit_depth, &color_type, &interlace_type,NULL, NULL);
 	
 	if(bit_depth == 16)
         png_set_strip_16(png_ptr);
@@ -88,7 +88,7 @@
 		png_set_expand(png_ptr);
 		png_read_update_info(png_ptr, info_ptr);
 		png_get_IHDR(png_ptr, info_ptr, &width, &height,
-			   &bit_depth, &color_type, &interlace_type,int_p_NULL, int_p_NULL);
+			   &bit_depth, &color_type, &interlace_type,NULL, NULL);
 	}
 	
 	if( color_type == PNG_COLOR_TYPE_GRAY ||
@@ -96,7 +96,7 @@
 		png_set_gray_to_rgb(png_ptr);
 		png_read_update_info(png_ptr, info_ptr);
 		png_get_IHDR(png_ptr, info_ptr, &width, &height,
-			   &bit_depth, &color_type, &interlace_type,int_p_NULL, int_p_NULL);
+			   &bit_depth, &color_type, &interlace_type,NULL, NULL);
 	}
 		
 	this->width=width;
@@ -114,7 +114,7 @@
 	}
 	
 	png_read_end(png_ptr, info_ptr);
-	png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL);
+	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
 	fclose(fp);
 }
 
