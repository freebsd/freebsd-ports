--- components/optimization_guide/core/optimization_guide_features.cc.orig	2026-04-28 21:06:17 UTC
+++ components/optimization_guide/core/optimization_guide_features.cc
@@ -97,7 +97,7 @@ BASE_FEATURE(kOptimizationGuideOnDeviceModel,
 // Whether to use the on device model service in optimization guide.
 BASE_FEATURE(kOptimizationGuideOnDeviceModel,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
