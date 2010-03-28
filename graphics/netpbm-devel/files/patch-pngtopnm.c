--- converter/other/pngtopnm.c.orig	2005-10-29 19:40:03.000000000 +0200
+++ converter/other/pngtopnm.c	2010-03-28 12:40:36.000000000 +0200
@@ -467,7 +467,7 @@
     bool retval;
 
     if (info_ptr->valid & PNG_INFO_tRNS) {
-        const png_color_16 * const transColorP = &info_ptr->trans_values;
+        const png_color_16 * const transColorP = &info_ptr->trans_color;
     
 
         /* There seems to be a problem here: you can't compare real
@@ -558,8 +558,8 @@
             for (i = 0, foundGray = FALSE;
                  i < info_ptr->num_trans && !foundGray;
                  ++i) {
-                if (info_ptr->trans[i] != 0 &&
-                    info_ptr->trans[i] != maxval) {
+                if (info_ptr->trans_alpha[i] != 0 &&
+                    info_ptr->trans_alpha[i] != maxval) {
                     foundGray = TRUE;
                 }
             }
@@ -630,7 +630,7 @@
                 unsigned int i;
                 trans_mix = TRUE;
                 for (i = 0; i < info_ptr->num_trans; ++i)
-                    if (info_ptr->trans[i] != 0 && info_ptr->trans[i] != 255) {
+                    if (info_ptr->trans_alpha[i] != 0 && info_ptr->trans_alpha[i] != 255) {
                         trans_mix = FALSE;
                         break;
                     }
@@ -874,7 +874,7 @@
                 setXel(&xelrow[col], fgColor, bgColor, alpha_handling,
                        ((info_ptr->valid & PNG_INFO_tRNS) &&
                         (fgColor.r == 
-                         gamma_correct(info_ptr->trans_values.gray,
+                         gamma_correct(info_ptr->trans_color.gray,
                                        totalgamma))) ?
                        0 : maxval);
             }
@@ -903,7 +903,7 @@
                 setXel(&xelrow[col], fgColor, bgColor, alpha_handling,
                        (info_ptr->valid & PNG_INFO_tRNS) &&
                        index < info_ptr->num_trans ?
-                       info_ptr->trans[index] : maxval);
+                       info_ptr->trans_alpha[index] : maxval);
             }
             break;
                 
