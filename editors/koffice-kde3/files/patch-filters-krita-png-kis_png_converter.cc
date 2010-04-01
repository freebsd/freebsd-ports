--- filters/krita/png/kis_png_converter.cc.orig	2007-05-30 23:39:37.000000000 +0200
+++ filters/krita/png/kis_png_converter.cc	2010-04-01 14:09:11.000000000 +0200
@@ -162,7 +162,7 @@
     }
     png_byte signature[8];
     fread(signature, 1, 8, fp);
-    if (!png_check_sig(signature, 8))
+    if (png_sig_cmp(signature, 0, 8))
     {
         return (KisImageBuilder_RESULT_BAD_FETCH);
     }
@@ -785,7 +785,7 @@
 
 void KisPNGConverter::progress(png_structp png_ptr, png_uint_32 row_number, int pass)
 {
-    if(png_ptr == NULL || row_number > PNG_MAX_UINT || pass > 7) return;
+    if(png_ptr == NULL || row_number > PNG_UINT_31_MAX || pass > 7) return;
 //     setProgress(row_number);
 }
 
