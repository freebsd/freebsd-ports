--- src/cairo_ft_font.c.orig	Tue Nov  9 21:53:24 2004
+++ src/cairo_ft_font.c	Tue Nov  9 21:58:25 2004
@@ -481,6 +481,9 @@
 			       cairo_glyph_t		**glyphs, 
 			       int			*nglyphs)
 {
+    double x, y;
+    FT_ULong *ucs4 = NULL;
+    size_t i;
     cairo_ft_font_t *font = abstract_font;
     FT_Face face = font->val->face;
     cairo_glyph_cache_key_t key;
@@ -490,9 +493,7 @@
     key.unscaled = &font->base;
     key.scale = *sc;
 
-    double x = 0., y = 0.;
-    size_t i;
-    FT_ULong *ucs4 = NULL; 
+    x = 0., y = 0.;
 
     _utf8_to_ucs4 (utf8, &ucs4, nglyphs);
 
