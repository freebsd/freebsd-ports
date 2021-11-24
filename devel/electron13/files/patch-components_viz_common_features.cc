--- components/viz/common/features.cc.orig	2021-07-15 19:13:38 UTC
+++ components/viz/common/features.cc
@@ -38,7 +38,7 @@ const base::Feature kEnableOverlayPrioritization {
 const base::Feature kUseSkiaRenderer {
   "UseSkiaRenderer",
 #if defined(OS_WIN) || defined(OS_ANDROID) || BUILDFLAG(IS_CHROMEOS_LACROS) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
