--- converter/other/pnmtopng.c.orig	2009-08-01 21:31:33.000000000 +0200
+++ converter/other/pnmtopng.c	2010-05-21 09:59:36.000000000 +0200
@@ -63,7 +63,7 @@
 #include "mallocvar.h"
 #include "nstring.h"
 
-#if PNG_LIBPNG_VER >= 10400
+#if 0
 #error Your PNG library (<png.h>) is incompatible with this Netpbm source code.
 #error You need either an older PNG library (older than 1.4)
 #error newer Netpbm source code (at least 10.48)
@@ -1869,7 +1869,7 @@
     info_ptr->num_palette = palette_size;
     if (trans_size > 0) {
         info_ptr->valid |= PNG_INFO_tRNS;
-        info_ptr->trans = trans;
+        info_ptr->trans_alpha = trans;
         info_ptr->num_trans = trans_size;   /* omit opaque values */
     }
     /* creating hIST chunk */
@@ -1906,7 +1906,7 @@
         info_ptr->color_type == PNG_COLOR_TYPE_RGB) {
         if (transparent > 0) {
             info_ptr->valid |= PNG_INFO_tRNS;
-            info_ptr->trans_values = 
+            info_ptr->trans_color = 
                 xelToPngColor_16(transcolor, maxval, png_maxval);
         }
     } else {
@@ -1918,10 +1918,10 @@
         if (info_ptr->valid && PNG_INFO_tRNS) 
             pm_message("Transparent color {gray, red, green, blue} = "
                        "{%d, %d, %d, %d}",
-                       info_ptr->trans_values.gray,
-                       info_ptr->trans_values.red,
-                       info_ptr->trans_values.green,
-                       info_ptr->trans_values.blue);
+                       info_ptr->trans_color.gray,
+                       info_ptr->trans_color.red,
+                       info_ptr->trans_color.green,
+                       info_ptr->trans_color.blue);
         else
             pm_message("No transparent color");
     }
