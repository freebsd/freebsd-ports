--- src/pngwriter.cc.orig	2009-02-10 22:45:16.000000000 +0100
+++ src/pngwriter.cc	2012-05-07 20:50:38.000000000 +0200
@@ -988,19 +988,19 @@
    time(&gmt);
    png_convert_from_time_t(&mod_time, gmt);
    png_set_tIME(png_ptr, info_ptr, &mod_time);
-   text_ptr[0].key = "Title";
+   text_ptr[0].key = (char*)"Title";
    text_ptr[0].text = texttitle_;
    text_ptr[0].compression = PNG_TEXT_COMPRESSION_NONE;
-   text_ptr[1].key = "Author";
+   text_ptr[1].key = (char*)"Author";
    text_ptr[1].text = textauthor_;
    text_ptr[1].compression = PNG_TEXT_COMPRESSION_NONE;
-   text_ptr[2].key = "Description";
+   text_ptr[2].key = (char*)"Description";
    text_ptr[2].text = textdescription_;
    text_ptr[2].compression = PNG_TEXT_COMPRESSION_NONE;
-   text_ptr[3].key = "Creation Time";
-   text_ptr[3].text = png_convert_to_rfc1123(png_ptr, &mod_time);
+   text_ptr[3].key = (char*)"Creation Time";
+   text_ptr[3].text = (char *)png_convert_to_rfc1123(png_ptr, &mod_time);
    text_ptr[3].compression = PNG_TEXT_COMPRESSION_NONE;
-   text_ptr[4].key = "Software";
+   text_ptr[4].key = (char*)"Software";
    text_ptr[4].text = textsoftware_;
    text_ptr[4].compression = PNG_TEXT_COMPRESSION_NONE;
    png_set_text(png_ptr, info_ptr, text_ptr, 5);
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
    
@@ -1530,7 +1530,7 @@
 	fclose(fp);
 	return 0;
      }
-   if (setjmp((*png_ptr)->jmpbuf)) /*(setjmp(png_jmpbuf(*png_ptr)) )*//////////////////////////////////////
+   if (setjmp( png_jmpbuf((*png_ptr))))
      {
 	png_destroy_read_struct(png_ptr, info_ptr, (png_infopp)NULL);
 	std::cerr << " PNGwriter::read_png_info - ERROR **: This file may be a corrupted PNG file. (setjmp(*png_ptr)->jmpbf) failed)." << std::endl;
