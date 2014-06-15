--- app/drawable.h.orig	2013-11-05 11:07:39.000000000 +0300
+++ app/drawable.h	2013-11-05 11:08:18.000000000 +0300
@@ -32,7 +32,7 @@
 #define GIMP_DRAWABLE_CLASS(klass) GTK_CHECK_CLASS_CAST (klass, GIMP_TYPE_DRAWABLE, GimpDrawableClass)
 #define GIMP_IS_DRAWABLE(obj)      GTK_CHECK_TYPE (obj, GIMP_TYPE_DRAWABLE)
 
-guint gimp_drawable_get_type (void);
+GtkType gimp_drawable_get_type (void);
 
 
 /*  drawable access functions  */
