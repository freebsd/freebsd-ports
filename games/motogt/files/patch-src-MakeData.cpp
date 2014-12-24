--- src/MakeData.cpp.orig	2011-01-10 17:40:30 UTC
+++ src/MakeData.cpp
@@ -5,6 +5,7 @@
 #define PNG_DEBUG 3
 #include <png.h>
 #include <fstream>
+#include <sys/stat.h>
 #include "global.h"
 #include "Config.h"
 #include "Confirm.h"
@@ -109,10 +110,10 @@ struct PngFile {
 		
 		png_read_info(png_ptr, info_ptr);
 		
-		width = info_ptr->width;
-		height = info_ptr->height;
-		color_type = info_ptr->color_type;
-		bit_depth = info_ptr->bit_depth;
+		width = png_get_image_width(png_ptr, info_ptr);
+		height = png_get_image_height(png_ptr, info_ptr);
+		color_type = png_get_color_type(png_ptr, info_ptr);
+		bit_depth = png_get_bit_depth(png_ptr, info_ptr);
 		
 		number_of_passes = png_set_interlace_handling(png_ptr);
 		png_read_update_info(png_ptr, info_ptr);
@@ -125,7 +126,7 @@ struct PngFile {
 		
 		row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
 		for (int y=0; y<height; y++)
-			row_pointers[y] = (png_byte*) malloc(info_ptr->rowbytes);
+			row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(png_ptr,info_ptr));
 		
 		png_read_image(png_ptr, row_pointers);
 		
@@ -376,7 +377,12 @@ struct PngFile {
 				}
 				fname[2]='0'+i; 
 				fname[1]='0'+j;
-				if (!f2->Save((dir+fname).c_str()))
+				size_t pos = 0;
+				do {
+					pos = dir.find('/', pos+1);
+					mkdir((home_dir+dir.substr(0, pos)).c_str(), 0755);
+				} while (pos != string::npos);
+				if (!f2->Save((home_dir+dir+fname).c_str()))
 					return false;
 				f2->width=ancho2; f2->height=ancho2;
 			}
