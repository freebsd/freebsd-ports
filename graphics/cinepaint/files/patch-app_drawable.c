--- app/drawable.c.orig	2013-11-05 11:07:48.000000000 +0300
+++ app/drawable.c	2013-11-05 11:09:02.000000000 +0300
@@ -56,10 +56,10 @@
 
 static CanvasDrawableClass *parent_class = NULL;
 
-guint
+GtkType
 gimp_drawable_get_type ()
 {
-  static guint drawable_type = 0;
+  static GtkType drawable_type = 0;
 
   if (!drawable_type)
     {
