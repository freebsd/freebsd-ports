--- src/extension/internal/pdfinput/poppler-transition-api.h.orig	2025-07-25 10:14:52 UTC
+++ src/extension/internal/pdfinput/poppler-transition-api.h
@@ -15,6 +15,16 @@
 #include <glib/poppler-features.h>
 #include <poppler/UTF.h>
 
+#if POPPLER_CHECK_VERSION(26, 2, 0)
+#define _POPPLER_WMODE GfxFont::WritingMode
+#define _POPPLER_WMODE_HORIZONTAL GfxFont::WritingMode::Horizontal
+#define _POPPLER_WMODE_VERTICAL GfxFont::WritingMode::Vertical
+#else
+#define _POPPLER_WMODE int
+#define _POPPLER_WMODE_HORIZONTAL 0
+#define _POPPLER_WMODE_VERTICAL 1
+#endif
+
 #if POPPLER_CHECK_VERSION(25, 7, 0)
 #define _POPPLER_TEXT_SHIFT_WITH_USER_COORDS(dx, dy) textShiftWithUserCoords(dx, dy)
 #define _POPPLER_FOFI_TRUETYPE_MAKE(font_data, faceIndex) FoFiTrueType::make(std::span(font_data), faceIndex)
@@ -62,11 +72,11 @@
 #endif
 
 #if POPPLER_CHECK_VERSION(24, 5, 0)
-#define _POPPLER_HAS_UNICODE_BOM(value) (hasUnicodeByteOrderMark(value->toStr()))
-#define _POPPLER_HAS_UNICODE_BOMLE(value) (hasUnicodeByteOrderMarkLE(value->toStr()))
+#define _POPPLER_HAS_UNICODE_BOM(value) (hasUnicodeByteOrderMark(value))
+#define _POPPLER_HAS_UNICODE_BOMLE(value) (hasUnicodeByteOrderMarkLE(value))
 #else
-#define _POPPLER_HAS_UNICODE_BOM(value) (value->hasUnicodeMarker())
-#define _POPPLER_HAS_UNICODE_BOMLE(value) (value->hasUnicodeMarkerLE())
+#define _POPPLER_HAS_UNICODE_BOM(value) (GooString(value).hasUnicodeMarker())
+#define _POPPLER_HAS_UNICODE_BOMLE(value) (GooString(value).hasUnicodeMarkerLE())
 #endif
 
 #if POPPLER_CHECK_VERSION(24, 3, 0)
