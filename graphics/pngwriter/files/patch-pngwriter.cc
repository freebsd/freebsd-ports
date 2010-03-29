--- src/pngwriter.cc.orig	2009-02-10 22:45:16.000000000 +0100
+++ src/pngwriter.cc	2010-03-29 15:55:32.000000000 +0200
@@ -1204,8 +1204,8 @@
    FILE            *fp;
    png_structp     png_ptr;
    png_infop       info_ptr;
-   unsigned char   **image;
-   unsigned long   width, height;
+   png_byte        **image;
+   png_uint_32     width, height;
    int bit_depth, color_type, interlace_type;
    //   png_uint_32     i;
    //
@@ -1311,7 +1311,7 @@
    if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth<8) 
      { 
 	// png_set_expand(png_ptr); 
-	png_set_gray_1_2_4_to_8(png_ptr);  // Just an alias of the above.
+	png_set_expand_gray_1_2_4_to_8(png_ptr);  // Just an alias of the above.
 	transformation_ = 1; 
      } 
    
