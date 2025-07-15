--- components/gwp_asan/client/gwp_asan_features.cc.orig	2024-02-21 00:20:41 UTC
+++ components/gwp_asan/client/gwp_asan_features.cc
@@ -9,7 +9,7 @@ namespace gwp_asan::internal {
 namespace gwp_asan::internal {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) ||                                          \
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) ||                     \
     (BUILDFLAG(IS_ANDROID) && defined(ARCH_CPU_64_BITS))
 constexpr base::FeatureState kDefaultEnabled = base::FEATURE_ENABLED_BY_DEFAULT;
 #else
