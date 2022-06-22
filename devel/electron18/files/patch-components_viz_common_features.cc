--- components/viz/common/features.cc.orig	2022-05-19 05:17:41 UTC
+++ components/viz/common/features.cc
@@ -67,7 +67,7 @@ const base::Feature kUseSkiaRenderer {
   "UseSkiaRenderer",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) ||           \
     BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
