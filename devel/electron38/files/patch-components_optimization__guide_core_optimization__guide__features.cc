--- components/optimization_guide/core/optimization_guide_features.cc.orig	2025-08-26 20:49:50 UTC
+++ components/optimization_guide/core/optimization_guide_features.cc
@@ -119,7 +119,7 @@ BASE_FEATURE(kOptimizationGuideOnDeviceModel,
 BASE_FEATURE(kOptimizationGuideOnDeviceModel,
              "OptimizationGuideOnDeviceModel",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
