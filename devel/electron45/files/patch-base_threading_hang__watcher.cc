--- base/threading/hang_watcher.cc.orig	2026-04-28 21:06:17 UTC
+++ base/threading/hang_watcher.cc
@@ -236,7 +236,7 @@ constexpr base::FeatureState HangWatcherFeatureDefault
 
 constexpr base::FeatureState HangWatcherFeatureDefault() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return FEATURE_ENABLED_BY_DEFAULT;
 #else
   return FEATURE_DISABLED_BY_DEFAULT;
