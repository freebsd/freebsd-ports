--- src/extension/internal/pdfinput/svg-builder.cpp.orig	2025-12-26 00:35:50 UTC
+++ src/extension/internal/pdfinput/svg-builder.cpp
@@ -32,6 +32,7 @@
 #include <poppler/GfxState.h>
 #include <poppler/Page.h>
 #include <poppler/Stream.h>
+#include <poppler/goo/gmem.h>
 
 #include "color.h"
 #include "color/cms-util.h"
@@ -1385,7 +1386,7 @@ void SvgBuilder::updateFont(GfxState *state, std::shar
     sp_repr_css_set_property(_css_font, "font-variant", "normal");
 
     // Writing mode
-    if ( font->getWMode() == 0 ) {
+    if ( font->getWMode() == _POPPLER_WMODE_HORIZONTAL ) {
         sp_repr_css_set_property(_css_font, "writing-mode", "lr");
     } else {
         sp_repr_css_set_property(_css_font, "writing-mode", "tb");
@@ -1397,7 +1398,7 @@ void SvgBuilder::updateTextShift(GfxState *state, doub
  */
 void SvgBuilder::updateTextShift(GfxState *state, double shift) {
     double shift_value = -shift * 0.001 * fabs(state->getFontSize());
-    if (state->getFont()->getWMode()) {
+    if (state->getFont()->getWMode() != _POPPLER_WMODE_HORIZONTAL) {
         _text_position[1] += shift_value;
     } else {
         _text_position[0] += shift_value;
@@ -1451,7 +1452,7 @@ Inkscape::XML::Node* SvgBuilder::_flushTextText(GfxSta
 
     // Text direction is a property of the <text> element.
     auto font = state->getFont();
-    if (font->getWMode() == 1) {
+    if (font->getWMode() == _POPPLER_WMODE_VERTICAL) {
         // Only set if vertical.
         auto css_text = sp_repr_css_attr_new();
         sp_repr_css_set_property(css_text, "writing-mode", "tb");
@@ -1545,8 +1546,8 @@ Inkscape::XML::Node* SvgBuilder::_flushTextText(GfxSta
         bool output_tspan =
             next_it == _glyphs.end() ||
             next_it->style_changed   ||
-            (writing_mode == 0 && std::abs(glyph.text_position[1] - next_it->text_position[1]) > 0.1) ||
-            (writing_mode == 1 && std::abs(glyph.text_position[0] - next_it->text_position[0]) > 0.1);
+            (writing_mode == _POPPLER_WMODE_HORIZONTAL && std::abs(glyph.text_position[1] - next_it->text_position[1]) > 0.1) ||
+            (writing_mode == _POPPLER_WMODE_VERTICAL   && std::abs(glyph.text_position[0] - next_it->text_position[0]) > 0.1);
 
         if (output_tspan) {
 
@@ -2093,7 +2094,11 @@ Inkscape::XML::Node *SvgBuilder::_createImage(Stream *
         } else {
             image_stream = new ImageStream(str, width, 1, 1);
         }
+#if POPPLER_CHECK_VERSION(26, 0, 0)
+        image_stream->rewind();
+#else
         image_stream->reset();
+#endif
 
         // Convert grayscale values
         unsigned char *buffer = new unsigned char[width];
@@ -2119,7 +2124,11 @@ Inkscape::XML::Node *SvgBuilder::_createImage(Stream *
         image_stream = new ImageStream(str, width,
                                        color_map->getNumPixelComps(),
                                        color_map->getBits());
+#if POPPLER_CHECK_VERSION(26, 0, 0)
+        image_stream->rewind();
+#else
         image_stream->reset();
+#endif
 
         // Convert RGB values
         unsigned int *buffer = new unsigned int[width];
