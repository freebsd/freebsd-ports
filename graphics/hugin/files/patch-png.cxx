--- src/foreign/vigra/vigra_impex/png.cxx.orig	2009-12-01 23:39:05.000000000 +0100
+++ src/foreign/vigra/vigra_impex/png.cxx	2010-03-29 13:22:16.000000000 +0200
@@ -272,7 +272,7 @@
         if ( color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8 ) {
             if (setjmp(png->jmpbuf))
                 vigra_postcondition( false,png_error_message.insert(0, "error in png_set_gray_1_2_4_to_8(): ").c_str());
-            png_set_gray_1_2_4_to_8(png);
+            png_set_expand_gray_1_2_4_to_8(png);
             bit_depth = 8;
         }
 
