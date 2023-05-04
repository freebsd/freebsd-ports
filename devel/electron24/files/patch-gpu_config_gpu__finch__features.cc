--- gpu/config/gpu_finch_features.cc.orig	2023-03-30 00:33:52 UTC
+++ gpu/config/gpu_finch_features.cc
@@ -57,7 +57,7 @@ bool IsDeviceBlocked(const char* field, const std::str
 BASE_FEATURE(kUseGles2ForOopR,
              "UseGles2ForOopR",
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_DISABLED_BY_DEFAULT
 #else
              base::FEATURE_ENABLED_BY_DEFAULT
@@ -135,7 +135,8 @@ const base::FeatureParam<std::string>
 BASE_FEATURE(kDefaultEnableGpuRasterization,
              "DefaultEnableGpuRasterization",
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
+    BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
