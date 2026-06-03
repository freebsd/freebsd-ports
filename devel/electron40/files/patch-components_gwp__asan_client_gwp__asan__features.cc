--- components/gwp_asan/client/gwp_asan_features.cc.orig	2025-08-26 20:49:50 UTC
+++ components/gwp_asan/client/gwp_asan_features.cc
@@ -9,7 +9,7 @@ namespace gwp_asan::internal {
 namespace gwp_asan::internal {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) ||                                          \
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) ||                     \
     (BUILDFLAG(IS_ANDROID) && defined(ARCH_CPU_64_BITS))
 constexpr base::FeatureState kDefaultEnabled = base::FEATURE_ENABLED_BY_DEFAULT;
 #else
@@ -72,7 +72,7 @@ GWP_ASAN_EXPORT extern const base::FeatureParam<int>
     kGwpAsanMallocGpuAllocationSamplingRange{&kGwpAsanMalloc,
                                              "GpuAllocationSamplingRange", 16};
 
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // Browser reservation params.
 GWP_ASAN_EXPORT extern const base::FeatureParam<int>
