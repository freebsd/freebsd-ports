--- src/osgPlugins/png/ReaderWriterPNG.cpp.orig	2010-03-28 16:40:42.000000000 -0600
+++ src/osgPlugins/png/ReaderWriterPNG.cpp	2010-03-28 16:41:42.000000000 -0600
@@ -173,7 +173,7 @@
                 endinfo = png_create_info_struct(png);
 
                 fin.read((char*)header,8);
-                if (fin.gcount() == 8 && png_check_sig(header, 8))
+                if (fin.gcount() == 8 && (png_sig_cmp(header, 0, 8) == 0))
                     png_set_read_fn(png,&fin,png_read_istream); //Use custom read function that will get data from istream
                 else
                 {
@@ -224,7 +224,7 @@
                 if (color == PNG_COLOR_TYPE_PALETTE)
                     png_set_palette_to_rgb(png);
                 if (color == PNG_COLOR_TYPE_GRAY && depth < 8)
-                    png_set_gray_1_2_4_to_8(png);
+                    png_set_expand_gray_1_2_4_to_8(png);
                 if (png_get_valid(png, info, PNG_INFO_tRNS))
                     png_set_tRNS_to_alpha(png);
 
