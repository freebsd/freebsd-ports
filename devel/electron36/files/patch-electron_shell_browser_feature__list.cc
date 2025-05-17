--- electron/shell/browser/feature_list.cc.orig	2025-05-07 07:36:13 UTC
+++ electron/shell/browser/feature_list.cc
@@ -28,7 +28,7 @@
 #include "pdf/pdf_features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/printing_features.h"
 #endif
 
