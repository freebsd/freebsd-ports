--- src/cairo_font.c.orig	Thu Jan 13 09:37:40 2005
+++ src/cairo_font.c	Wed Feb 16 00:50:47 2005
@@ -85,9 +85,11 @@
 			  void *key,
 			  void **return_value)
 {
-    const cairo_font_backend_t *backend = CAIRO_FONT_BACKEND_DEFAULT;
+    const cairo_font_backend_t *backend;
     cairo_font_cache_key_t *k;
     cairo_font_cache_entry_t *entry;
+
+    backend = CAIRO_FONT_BACKEND_DEFAULT;
     k = (cairo_font_cache_key_t *) key;
 
     /* XXX: The current freetype backend may return NULL, (for example
