-- Ensure public PDFium API symbols are exported when building libpdfium.so
-- with hidden default visibility (non-component build).  This makes the
-- shared library usable for dynamic loaders such as pypdfium2/ctypes.
--- public/fpdfview.h.orig	2026-09-24 10:21:29 UTC
+++ public/fpdfview.h
@@ -220,7 +220,11 @@ typedef int FPDF_OBJECT_TYPE;
 #endif  // defined(FPDF_IMPLEMENTATION)
 #endif  // defined(WIN32)
 #else
+#if defined(WIN32)
 #define FPDF_EXPORT
+#else
+#define FPDF_EXPORT __attribute__((visibility("default")))
+#endif
 #endif  // defined(COMPONENT_BUILD)
 
 #if defined(WIN32) && defined(FPDFSDK_EXPORTS)
