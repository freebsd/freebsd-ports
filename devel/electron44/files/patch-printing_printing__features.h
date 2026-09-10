--- printing/printing_features.h.orig	2026-06-23 23:37:18 UTC
+++ printing/printing_features.h
@@ -19,7 +19,7 @@ BASE_DECLARE_FEATURE(kAlignPdfDefaultPrintSettingsWith
 COMPONENT_EXPORT(PRINTING_BASE)
 BASE_DECLARE_FEATURE(kAlignPdfDefaultPrintSettingsWithHTML);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kCupsIppPrintingBackend);
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kLinuxXdgPrintPortal);
 #endif  // BUILDFLAG(IS_LINUX)
