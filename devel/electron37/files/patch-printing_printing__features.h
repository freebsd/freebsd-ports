--- printing/printing_features.h.orig	2025-04-22 20:15:27 UTC
+++ printing/printing_features.h
@@ -24,7 +24,7 @@ BASE_DECLARE_FEATURE(kApiPrintingMarginsAndScale);
 BASE_DECLARE_FEATURE(kApiPrintingMarginsAndScale);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kCupsIppPrintingBackend);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
 
