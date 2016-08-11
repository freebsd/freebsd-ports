--- vcl/source/glyphs/graphite_layout.cxx.orig	2014-02-25 08:33:06 UTC
+++ vcl/source/glyphs/graphite_layout.cxx
@@ -107,9 +107,10 @@ namespace
     typedef ext_std::pair<gr::GlyphIterator, gr::GlyphIterator>       glyph_range_t;
     typedef ext_std::pair<gr::GlyphSetIterator, gr::GlyphSetIterator> glyph_set_range_t;
 
-    inline long round(const float n) {
+    inline long round_(const float n) {
         return long(n + (n < 0 ? -0.5 : 0.5));
     }
+#define round round_
 
 
     template<typename T>
