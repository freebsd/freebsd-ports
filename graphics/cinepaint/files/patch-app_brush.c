--- app/brush.c.orig	2013-11-05 10:57:08.000000000 +0300
+++ app/brush.c	2013-11-05 10:58:06.000000000 +0300
@@ -102,7 +102,7 @@
 
 GtkType gimp_brush_get_type(void)
 {
-  static GtkType type;
+  static GtkType type = 0;
   if(!type){
 #if GTK_MAJOR_VERSION > 1
       static const GTypeInfo info =
