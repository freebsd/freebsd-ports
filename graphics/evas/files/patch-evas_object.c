--- src/evas_object.c.orig	Sun Aug 15 16:22:01 2004
+++ src/evas_object.c	Sun Aug 15 16:22:07 2004
@@ -10,6 +10,8 @@
 #define RECTS_INTERSECT(x, y, w, h, xx, yy, ww, hh) \
 ((SPANS_COMMON((x), (w), (xx), (ww))) && (SPANS_COMMON((y), (h), (yy), (hh))))
 
+void _evas_cleanup_clip(Evas e, Evas_Object o);
+
 Evas_Layer
 _evas_get_object_layer(Evas e, Evas_Object o)
 {
