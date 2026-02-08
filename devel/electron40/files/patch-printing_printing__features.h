--- printing/printing_features.h.orig	2026-01-07 00:52:53 UTC
+++ printing/printing_features.h
@@ -27,7 +27,7 @@ BASE_DECLARE_FEATURE(kAlignPdfDefaultPrintSettingsWith
 COMPONENT_EXPORT(PRINTING_BASE)
 BASE_DECLARE_FEATURE(kAlignPdfDefaultPrintSettingsWithHTML);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kCupsIppPrintingBackend);
 #endif  // BUILDFLAG(IS_LINUX)
 
