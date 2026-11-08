--- electron/shell/browser/feature_list.cc.orig	2026-08-31 00:54:19 UTC
+++ electron/shell/browser/feature_list.cc
@@ -32,7 +32,7 @@
 #include "pdf/pdf_features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/printing_features.h"
 #endif
 
