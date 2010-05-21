--- converter/other/pngtopnm.c.orig	2009-08-01 21:35:54.000000000 +0200
+++ converter/other/pngtopnm.c	2010-05-21 10:04:14.000000000 +0200
@@ -43,7 +43,7 @@
 #include "nstring.h"
 #include "shhopt.h"
 
-#if PNG_LIBPNG_VER >= 10400
+#if 0
 #error Your PNG library (<png.h>) is incompatible with this Netpbm source code.
 #error You need either an older PNG library (older than 1.4)
 #error newer Netpbm source code (at least 10.48)
@@ -500,7 +500,7 @@
             case PNG_COLOR_TYPE_GRAY:
                 setXel(&xelrow[col], c, c, c,
                        ((info_ptr->valid & PNG_INFO_tRNS) &&
-                        (c == gamma_correct(info_ptr->trans_values.gray,
+                        (c == gamma_correct(info_ptr->trans_color.gray,
                                             totalgamma))) ?
                        0 : maxval);
                 break;
@@ -517,7 +517,7 @@
                        info_ptr->palette[c].blue,
                        (info_ptr->valid & PNG_INFO_tRNS) &&
                        c < info_ptr->num_trans ?
-                       info_ptr->trans[c] : maxval);
+                       info_ptr->trans_alpha[c] : maxval);
                 break;
 
             case PNG_COLOR_TYPE_RGB: {
@@ -525,11 +525,11 @@
                 png_uint_16 const c3 = get_png_val(png_pixelP);
                 setXel(&xelrow[col], c, c2, c3,
                        ((info_ptr->valid & PNG_INFO_tRNS) &&
-                        (c == gamma_correct(info_ptr->trans_values.red,
+                        (c == gamma_correct(info_ptr->trans_color.red,
                                             totalgamma)) &&
-                        (c2 == gamma_correct(info_ptr->trans_values.green,
+                        (c2 == gamma_correct(info_ptr->trans_color.green,
                                              totalgamma)) &&
-                        (c3 == gamma_correct(info_ptr->trans_values.blue,
+                        (c3 == gamma_correct(info_ptr->trans_color.blue,
                                              totalgamma))) ?
                        0 : maxval);
             }
@@ -694,7 +694,7 @@
             (info_ptr->valid & PNG_INFO_tRNS)) {
           trans_mix = TRUE;
           for (i = 0 ; i < info_ptr->num_trans ; i++)
-            if (info_ptr->trans[i] != 0 && info_ptr->trans[i] != 255) {
+            if (info_ptr->trans_alpha[i] != 0 && info_ptr->trans_alpha[i] != 255) {
               trans_mix = FALSE;
               break;
             }
@@ -847,7 +847,7 @@
         pnm_type = PBM_TYPE;
         if (info_ptr->valid & PNG_INFO_tRNS) {
           for (i = 0 ; i < info_ptr->num_trans ; i++) {
-            if (info_ptr->trans[i] != 0 && info_ptr->trans[i] != maxval) {
+            if (info_ptr->trans_alpha[i] != 0 && info_ptr->trans_alpha[i] != maxval) {
               pnm_type = PGM_TYPE;
               break;
             }
