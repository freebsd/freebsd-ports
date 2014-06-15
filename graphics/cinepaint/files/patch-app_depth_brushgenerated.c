--- app/depth/brushgenerated.c.orig	2013-11-05 11:32:19.000000000 +0300
+++ app/depth/brushgenerated.c	2013-11-05 11:34:56.000000000 +0300
@@ -106,9 +106,9 @@
   brush->freeze        = 0;
 }
 
-guint gimp_brush_generated_get_type(void)
+GtkType gimp_brush_generated_get_type(void)
 {
-  static GtkType type;
+  static GtkType type = 0;
   if(!type){
     GtkTypeInfo info={
       "GimpBrushGenerated",
