--- printing/printing_features.h.orig	2024-08-14 20:55:09 UTC
+++ printing/printing_features.h
@@ -22,7 +22,7 @@ BASE_DECLARE_FEATURE(kAddPrinterViaPrintscanmgr);
 BASE_DECLARE_FEATURE(kAddPrinterViaPrintscanmgr);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kCupsIppPrintingBackend);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
 
