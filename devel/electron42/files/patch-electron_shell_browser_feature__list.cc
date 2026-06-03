--- electron/shell/browser/feature_list.cc.orig	2026-01-15 18:39:20 UTC
+++ electron/shell/browser/feature_list.cc
@@ -30,7 +30,7 @@
 #include "pdf/pdf_features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/printing_features.h"
 #endif
 
