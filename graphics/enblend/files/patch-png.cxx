--- src/vigra_impex/png.cxx.orig	2007-11-25 00:46:55.000000000 +0100
+++ src/vigra_impex/png.cxx	2010-03-29 11:49:42.000000000 +0200
@@ -276,7 +276,7 @@
         if ( color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8 ) {
             if (setjmp(png->jmpbuf))
                 vigra_postcondition( false,png_error_message.insert(0, "error in png_set_gray_1_2_4_to_8(): ").c_str());
-            png_set_gray_1_2_4_to_8(png);
+            png_set_expand_gray_1_2_4_to_8(png);
             bit_depth = 8;
         }
 
