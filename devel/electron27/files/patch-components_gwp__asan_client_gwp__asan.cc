--- components/gwp_asan/client/gwp_asan.cc.orig	2023-10-19 19:58:18 UTC
+++ components/gwp_asan/client/gwp_asan.cc
@@ -64,7 +64,7 @@ constexpr bool kCpuIs64Bit =
 // ProcessSamplingBoost is the multiplier to increase the
 // ProcessSamplingProbability in scenarios where we want to perform additional
 // testing (e.g., on canary/dev builds).
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 constexpr int kDefaultMaxAllocations = 50;
 constexpr int kDefaultMaxMetadata = 210;
 constexpr int kDefaultTotalPages = kCpuIs64Bit ? 2048 : kDefaultMaxMetadata * 2;
@@ -84,7 +84,7 @@ constexpr int kDefaultProcessSamplingBoost2 = 10;
         // BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 constexpr base::FeatureState kDefaultEnabled = base::FEATURE_ENABLED_BY_DEFAULT;
 #else
 constexpr base::FeatureState kDefaultEnabled =
