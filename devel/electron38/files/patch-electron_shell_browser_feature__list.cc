--- electron/shell/browser/feature_list.cc.orig	2025-07-02 10:12:01 UTC
+++ electron/shell/browser/feature_list.cc
@@ -29,7 +29,7 @@
 #include "pdf/pdf_features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/printing_features.h"
 #endif
 
