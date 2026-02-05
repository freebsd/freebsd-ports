--- source/blender/blenfont/intern/blf_glyph.cc.orig	2025-12-28 17:06:06 UTC
+++ source/blender/blenfont/intern/blf_glyph.cc
@@ -1365,7 +1365,11 @@ GlyphBLF *blf_glyph_ensure(FontBLF *font, GlyphCacheBL
 
   if (!glyph_index) {
     /* 1 = id of ICON_CHAR_NOTDEF */
+#ifndef WITH_HEADLESS
     return blf_glyph_ensure_icon(gc, 1, false, nullptr);
+#else
+    return nullptr;
+#endif
   }
 
   if (!blf_ensure_face(font_with_glyph)) {
