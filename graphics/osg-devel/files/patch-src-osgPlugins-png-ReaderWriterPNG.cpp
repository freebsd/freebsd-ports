--- src/osgPlugins/png/ReaderWriterPNG.cpp.orig	2009-11-17 13:55:52.000000000 +0100
+++ src/osgPlugins/png/ReaderWriterPNG.cpp	2010-03-29 16:18:38.000000000 +0200
@@ -178,7 +178,7 @@
                 endinfo = png_create_info_struct(png);
 
                 fin.read((char*)header,8);
-                if (fin.gcount() == 8 && png_check_sig(header, 8))
+                if (fin.gcount() == 8 && !png_sig_cmp(header, 0, 8))
                     png_set_read_fn(png,&fin,png_read_istream); //Use custom read function that will get data from istream
                 else
                 {
@@ -229,7 +229,7 @@
                 if (color == PNG_COLOR_TYPE_PALETTE)
                     png_set_palette_to_rgb(png);
                 if (color == PNG_COLOR_TYPE_GRAY && depth < 8)
-                    png_set_gray_1_2_4_to_8(png);
+                    png_set_expand_gray_1_2_4_to_8(png);
                 if (png_get_valid(png, info, PNG_INFO_tRNS))
                     png_set_tRNS_to_alpha(png);
 
