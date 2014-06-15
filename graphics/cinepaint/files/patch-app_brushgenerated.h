--- app/brushgenerated.h.orig	2013-11-05 11:11:01.000000000 +0300
+++ app/brushgenerated.h	2013-11-05 11:11:39.000000000 +0300
@@ -51,7 +51,7 @@
 #define GIMP_BRUSH_GENERATED(obj)  (GIMP_CHECK_CAST ((obj), GIMP_TYPE_BRUSH_GENERATED, GimpBrushGenerated))
 #define GIMP_IS_BRUSH_GENERATED(obj) (GIMP_CHECK_TYPE ((obj), GIMP_TYPE_BRUSH_GENERATED))
 
-guint gimp_brush_generated_get_type (void);
+GtkType gimp_brush_generated_get_type (void);
 
 /* normal stuff */
 
