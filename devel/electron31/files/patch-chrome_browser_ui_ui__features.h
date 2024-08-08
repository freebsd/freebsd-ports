--- chrome/browser/ui/ui_features.h.orig	2024-06-18 21:43:24 UTC
+++ chrome/browser/ui/ui_features.h
@@ -288,7 +288,7 @@ BASE_DECLARE_FEATURE(kTopChromeWebUIUsesSpareRenderer)
 
 BASE_DECLARE_FEATURE(kTopChromeWebUIUsesSpareRenderer);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUpdateTextOptions);
 extern const base::FeatureParam<int> kUpdateTextOptionNumber;
 #endif
