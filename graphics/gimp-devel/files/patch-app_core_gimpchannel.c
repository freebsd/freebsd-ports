--- app/core/gimpchannel.c.orig	Thu Feb  5 01:46:50 2004
+++ app/core/gimpchannel.c	Thu Feb  5 01:46:59 2004
@@ -640,7 +640,7 @@
   else if (GIMP_IS_PAINT_INFO (stroke_desc))
     {
       GimpImage        *gimage     = gimp_item_get_image (item);
-      GimpPaintInfo    *paint_info = GIMP_PAINT_INFO (stroke_desc);;
+      GimpPaintInfo    *paint_info = GIMP_PAINT_INFO (stroke_desc);
       GimpPaintOptions *paint_options;
       GimpPaintCore    *core;
 
