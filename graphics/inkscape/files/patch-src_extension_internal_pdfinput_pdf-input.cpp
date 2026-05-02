--- src/extension/internal/pdfinput/pdf-input.cpp.orig	2025-12-26 00:35:50 UTC
+++ src/extension/internal/pdfinput/pdf-input.cpp
@@ -33,6 +33,7 @@
 #include <poppler/glib/poppler.h>
 #include <poppler/glib/poppler-document.h>
 #include <poppler/glib/poppler-page.h>
+#include <poppler/goo/gmem.h>
 #endif
 
 #include <gdkmm/general.h>
