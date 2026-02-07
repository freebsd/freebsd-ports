--- printing/printing_features.h.orig	2025-08-26 20:49:50 UTC
+++ printing/printing_features.h
@@ -24,7 +24,7 @@ BASE_DECLARE_FEATURE(kApiPrintingMarginsAndScale);
 BASE_DECLARE_FEATURE(kApiPrintingMarginsAndScale);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kCupsIppPrintingBackend);
 #endif  // BUILDFLAG(IS_LINUX)
 
