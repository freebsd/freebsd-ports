--- converter/other/pnmtopng.c.orig	2005-10-16 21:36:43.000000000 +0200
+++ converter/other/pnmtopng.c	2010-03-28 12:43:18.000000000 +0200
@@ -267,7 +267,7 @@
     unsigned int option_def_index;
 
     unsigned int alphaSpec, transparentSpec, backgroundSpec;
-    unsigned int textSpec, ztxtSpec, modtimeSpec, paletteSpec;
+    unsigned int textSpec, ztxtSpec, paletteSpec;
     unsigned int filterSpec;
 
     unsigned int nofilter, sub, up, avg, paeth, filter;
@@ -296,7 +296,7 @@
     OPTENT3(0, "ztxt",             OPT_STRING,    &cmdlineP->ztxt,
             &ztxtSpec,             0);
     OPTENT3(0, "modtime",          OPT_STRING,    &modtime,
-            &modtimeSpec,          0);
+            &cmdlineP->modtimeSpec,0);
     OPTENT3(0, "palette",          OPT_STRING,    &cmdlineP->palette,
             &paletteSpec,          0);
     OPTENT3(0, "compression",      OPT_UINT,
@@ -2486,7 +2486,7 @@
     info_ptr->num_palette = palette_size;
     if (trans_size > 0) {
         info_ptr->valid |= PNG_INFO_tRNS;
-        info_ptr->trans = trans;
+        info_ptr->trans_alpha = trans;
         info_ptr->num_trans = trans_size;   /* omit opaque values */
     }
     /* creating hIST chunk */
@@ -2523,7 +2523,7 @@
         info_ptr->color_type == PNG_COLOR_TYPE_RGB) {
         if (transparent > 0) {
             info_ptr->valid |= PNG_INFO_tRNS;
-            info_ptr->trans_values = 
+            info_ptr->trans_color = 
                 xelToPngColor_16(transcolor, maxval, png_maxval);
         }
     } else {
@@ -2535,10 +2535,10 @@
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
