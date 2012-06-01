--- converter/other/pngtopnm.c.orig	2011-11-25 01:15:46.000000000 +0100
+++ converter/other/pngtopnm.c	2012-04-24 22:15:14.000000000 +0200
@@ -37,6 +37,7 @@
 #include <math.h>
 #include <float.h>
 #include <png.h>    /* includes zlib.h and setjmp.h */
+#include <pngpriv.h>
 #define VERSION "2.37.4 (5 December 1999) +netpbm"
 
 #include "pnm.h"
@@ -44,7 +45,7 @@
 #include "nstring.h"
 #include "shhopt.h"
 
-#if PNG_LIBPNG_VER >= 10400
+#if 0
 #error Your PNG library (<png.h>) is incompatible with this Netpbm source code.
 #error You need either an older PNG library (older than 1.4)
 #error newer Netpbm source code (at least 10.48)
@@ -489,7 +490,7 @@
     bool retval;
 
     if (info_ptr->valid & PNG_INFO_tRNS) {
-        const png_color_16 * const transColorP = &info_ptr->trans_values;
+        const png_color_16 * const transColorP = &info_ptr->trans_color;
     
 
         /* There seems to be a problem here: you can't compare real
@@ -582,8 +583,8 @@
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
@@ -654,7 +655,7 @@
                 unsigned int i;
                 trans_mix = TRUE;
                 for (i = 0; i < info_ptr->num_trans; ++i)
-                    if (info_ptr->trans[i] != 0 && info_ptr->trans[i] != 255) {
+                    if (info_ptr->trans_alpha[i] != 0 && info_ptr->trans_alpha[i] != 255) {
                         trans_mix = FALSE;
                         break;
                     }
@@ -892,7 +893,7 @@
                 setXel(&xelrow[col], fgColor, bgColor, alpha_handling,
                        ((info_ptr->valid & PNG_INFO_tRNS) &&
                         (fgColor.r == 
-                         gamma_correct(info_ptr->trans_values.gray,
+                         gamma_correct(info_ptr->trans_color.gray,
                                        totalgamma))) ?
                        0 : maxval);
             }
@@ -921,7 +922,7 @@
                 setXel(&xelrow[col], fgColor, bgColor, alpha_handling,
                        (info_ptr->valid & PNG_INFO_tRNS) &&
                        index < info_ptr->num_trans ?
-                       info_ptr->trans[index] : maxval);
+                       info_ptr->trans_alpha[index] : maxval);
             }
             break;
                 
