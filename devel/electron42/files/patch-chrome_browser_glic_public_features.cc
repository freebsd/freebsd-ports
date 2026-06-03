--- chrome/browser/glic/public/features.cc.orig	2026-05-18 23:17:45 UTC
+++ chrome/browser/glic/public/features.cc
@@ -46,7 +46,7 @@ BASE_FEATURE(kGlicLiveMode,
 BASE_FEATURE(kGlicCreateTabAdjacent, base::FEATURE_ENABLED_BY_DEFAULT);
 
 BASE_FEATURE(kGlicLiveMode,
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_DISABLED_BY_DEFAULT
 #else
              base::FEATURE_ENABLED_BY_DEFAULT
