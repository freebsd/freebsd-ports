--- lib/pixmap.c.orig	2013-11-05 15:33:26.000000000 +0300
+++ lib/pixmap.c	2013-11-05 15:34:10.000000000 +0300
@@ -70,7 +70,7 @@
 GtkType
 gimp_pixmap_get_type (void)
 {
-  static guint pixmap_type = 0;
+  static GtkType pixmap_type = 0;
 
   if (!pixmap_type)
     {
