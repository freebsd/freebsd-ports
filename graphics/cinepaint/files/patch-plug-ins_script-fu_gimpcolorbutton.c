--- plug-ins/script-fu/gimpcolorbutton.c.orig	2013-11-05 15:42:43.000000000 +0300
+++ plug-ins/script-fu/gimpcolorbutton.c	2013-11-05 15:43:31.000000000 +0300
@@ -223,7 +223,7 @@
 GtkType
 gimp_color_button_get_type (void)
 {
-  static guint type = 0;
+  static GtkType type = 0;
 
   if (!type)
     {

