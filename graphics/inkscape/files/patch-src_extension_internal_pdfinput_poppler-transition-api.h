--- src/extension/internal/pdfinput/poppler-transition-api.h.orig	2019-01-15 04:29:27 UTC
+++ src/extension/internal/pdfinput/poppler-transition-api.h
@@ -3,6 +3,13 @@
 
 #include <glib/poppler-features.h>
 
+#if POPPLER_CHECK_VERSION(0, 76, 0)
+#define _POPPLER_NEW_PARSER(xref, obj) Parser(xref, obj, gFalse)
+#else
+#define _POPPLER_NEW_PARSER(xref, obj) Parser(xref, new Lexer(xref, obj), gFalse)
+#endif
+
+
 #if POPPLER_CHECK_VERSION(0, 72, 0)
 #define getCString c_str
 #endif
