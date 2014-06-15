--- app/depth/layer.c.orig	2013-11-05 11:28:32.000000000 +0300
+++ app/depth/layer.c	2013-11-05 11:30:50.000000000 +0300
@@ -65,10 +65,10 @@
 static CanvasDrawableClass *layer_parent_class = NULL;
 static GimpChannelClass *layer_mask_parent_class = NULL;
 
-guint
+GtkType 
 gimp_layer_get_type ()
 {
-  static guint layer_type = 0;
+  static GtkType layer_type = 0;
 
   if (!layer_type)
     {
@@ -118,10 +118,10 @@
 {
 }
 
-guint
+GtkType
 gimp_layer_mask_get_type ()
 {
-  static guint layer_mask_type = 0;
+  static GtkType layer_mask_type = 0;
 
   if (!layer_mask_type)
     {
