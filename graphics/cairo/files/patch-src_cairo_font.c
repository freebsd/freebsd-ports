--- src/cairo_font.c.orig	Tue Nov  9 21:51:24 2004
+++ src/cairo_font.c	Tue Nov  9 21:53:06 2004
@@ -54,9 +54,9 @@
 static unsigned long
 _font_cache_hash (void *cache, void *key)
 {
+    unsigned long hash;
     cairo_font_cache_key_t *in;
     in = (cairo_font_cache_key_t *) key;
-    unsigned long hash;
 
     /* 1607 and 1451 are just a couple random primes. */
     hash = _cairo_hash_string (in->family);
@@ -86,11 +86,12 @@
 			  void *key,
 			  void **return_value)
 {
+    const struct cairo_font_backend *backend; 
     cairo_font_cache_key_t *k;
     cairo_font_cache_entry_t *entry;
     k = (cairo_font_cache_key_t *) key;
 
-    const struct cairo_font_backend *backend = CAIRO_FONT_BACKEND_DEFAULT;
+    backend = CAIRO_FONT_BACKEND_DEFAULT;
 
     /* XXX: The current freetype backend may return NULL, (for example
      * if no fonts are installed), but I would like to guarantee that
