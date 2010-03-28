--- converter/other/pngtopnm.c.orig	2004-04-04 02:18:34.000000000 +0200
+++ converter/other/pngtopnm.c	2010-03-28 12:29:26.000000000 +0200
@@ -494,7 +494,7 @@
             case PNG_COLOR_TYPE_GRAY:
                 setXel(&xelrow[col], c, c, c,
                        ((info_ptr->valid & PNG_INFO_tRNS) &&
-                        (c == gamma_correct(info_ptr->trans_values.gray,
+                        (c == gamma_correct(info_ptr->trans_color.gray,
                                             totalgamma))) ?
                        0 : maxval);
                 break;
@@ -511,7 +511,7 @@
                        info_ptr->palette[c].blue,
                        (info_ptr->valid & PNG_INFO_tRNS) &&
                        c < info_ptr->num_trans ?
-                       info_ptr->trans[c] : maxval);
+                       info_ptr->trans_alpha[c] : maxval);
                 break;
 
             case PNG_COLOR_TYPE_RGB: {
@@ -519,11 +519,11 @@
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
@@ -688,7 +688,7 @@
             (info_ptr->valid & PNG_INFO_tRNS)) {
           trans_mix = TRUE;
           for (i = 0 ; i < info_ptr->num_trans ; i++)
-            if (info_ptr->trans[i] != 0 && info_ptr->trans[i] != 255) {
+            if (info_ptr->trans_alpha[i] != 0 && info_ptr->trans_alpha[i] != 255) {
               trans_mix = FALSE;
               break;
             }
@@ -841,7 +841,7 @@
         pnm_type = PBM_TYPE;
         if (info_ptr->valid & PNG_INFO_tRNS) {
           for (i = 0 ; i < info_ptr->num_trans ; i++) {
-            if (info_ptr->trans[i] != 0 && info_ptr->trans[i] != maxval) {
+            if (info_ptr->trans_alpha[i] != 0 && info_ptr->trans_alpha[i] != maxval) {
               pnm_type = PGM_TYPE;
               break;
             }
