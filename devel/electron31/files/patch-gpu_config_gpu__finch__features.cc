--- gpu/config/gpu_finch_features.cc.orig	2024-06-18 21:43:33 UTC
+++ gpu/config/gpu_finch_features.cc
@@ -137,7 +137,7 @@ BASE_FEATURE(kDefaultEnableGpuRasterization,
 BASE_FEATURE(kDefaultEnableGpuRasterization,
              "DefaultEnableGpuRasterization",
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -150,7 +150,7 @@ BASE_FEATURE(kCanvasOopRasterization,
              "CanvasOopRasterization",
 #if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_WIN) ||         \
     (BUILDFLAG(IS_MAC) && defined(ARCH_CPU_ARM64)) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
