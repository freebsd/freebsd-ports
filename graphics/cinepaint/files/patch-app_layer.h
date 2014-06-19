--- app/layer.h.orig	2013-11-05 10:49:42.000000000 +0300
+++ app/layer.h	2013-11-05 10:51:01.000000000 +0300
@@ -51,8 +51,8 @@
 #define GIMP_IS_LAYER_MASK(obj)      GTK_CHECK_TYPE (obj, gimp_layer_mask_get_type())
 
 
-guint gimp_layer_get_type (void);
-guint gimp_layer_mask_get_type (void);
+GtkType gimp_layer_get_type (void);
+GtkType gimp_layer_mask_get_type (void);
 
 /*  Special undo types  */
 
