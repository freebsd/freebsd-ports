--- converter/other/pnmtopng.c.orig	2007-07-04 05:26:21.000000000 +0200
+++ converter/other/pnmtopng.c	2010-03-28 12:17:40.000000000 +0200
@@ -1863,7 +1863,7 @@
     info_ptr->num_palette = palette_size;
     if (trans_size > 0) {
         info_ptr->valid |= PNG_INFO_tRNS;
-        info_ptr->trans = trans;
+        info_ptr->trans_alpha = trans;
         info_ptr->num_trans = trans_size;   /* omit opaque values */
     }
     /* creating hIST chunk */
@@ -1900,7 +1900,7 @@
         info_ptr->color_type == PNG_COLOR_TYPE_RGB) {
         if (transparent > 0) {
             info_ptr->valid |= PNG_INFO_tRNS;
-            info_ptr->trans_values = 
+            info_ptr->trans_color = 
                 xelToPngColor_16(transcolor, maxval, png_maxval);
         }
     } else {
@@ -1912,10 +1912,10 @@
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
