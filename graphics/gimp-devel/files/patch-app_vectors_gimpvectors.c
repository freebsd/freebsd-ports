--- app/vectors/gimpvectors.c.orig	Thu Feb  5 01:49:20 2004
+++ app/vectors/gimpvectors.c	Thu Feb  5 01:50:25 2004
@@ -545,7 +545,7 @@
                      GimpObject   *stroke_desc,
                      gboolean      use_default_values)
 {
-  GimpVectors *vectors = GIMP_VECTORS (item);;
+  GimpVectors *vectors = GIMP_VECTORS (item);
   gboolean     retval  = FALSE;
 
   if (! vectors->strokes)
@@ -564,7 +564,7 @@
   else if (GIMP_IS_PAINT_INFO (stroke_desc))
     {
       GimpImage        *gimage     = gimp_item_get_image (item);
-      GimpPaintInfo    *paint_info = GIMP_PAINT_INFO (stroke_desc);;
+      GimpPaintInfo    *paint_info = GIMP_PAINT_INFO (stroke_desc);
       GimpPaintOptions *paint_options;
       GimpPaintCore    *core;
 
