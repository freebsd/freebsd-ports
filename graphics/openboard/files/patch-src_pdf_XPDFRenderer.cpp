--- src/pdf/XPDFRenderer.cpp.orig	2026-03-23 11:30:46 UTC
+++ src/pdf/XPDFRenderer.cpp
@@ -178,7 +178,9 @@ QString XPDFRenderer::title() const
 #endif
             if (title.isString())
             {
-#if POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 72
+#if POPPLER_VERSION_MAJOR > 26 || (POPPLER_VERSION_MAJOR == 26 && POPPLER_VERSION_MINOR >= 4)
+                return QString(title.getString().c_str());
+#elif POPPLER_VERSION_MAJOR > 0 || POPPLER_VERSION_MINOR >= 72
                 return QString(title.getString()->c_str());
 #else
                 return QString(title.getString()->getCString());
