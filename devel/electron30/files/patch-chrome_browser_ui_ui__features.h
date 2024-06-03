--- chrome/browser/ui/ui_features.h.orig	2024-04-15 20:33:49 UTC
+++ chrome/browser/ui/ui_features.h
@@ -264,7 +264,7 @@ BASE_DECLARE_FEATURE(kTopChromeWebUIUsesSpareRenderer)
 
 BASE_DECLARE_FEATURE(kTopChromeWebUIUsesSpareRenderer);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUpdateTextOptions);
 extern const base::FeatureParam<int> kUpdateTextOptionNumber;
 #endif
