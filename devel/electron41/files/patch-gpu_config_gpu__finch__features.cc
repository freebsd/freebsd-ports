--- gpu/config/gpu_finch_features.cc.orig	2026-03-13 16:54:03 UTC
+++ gpu/config/gpu_finch_features.cc
@@ -110,7 +110,7 @@ BASE_FEATURE(kRemoveGPULegacyIPC, base::FEATURE_DISABL
 // of associating with an unused IPC::Channel.
 BASE_FEATURE(kRemoveGPULegacyIPC, base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Feature flag to control whether SharedImageStub sequence uses high priority
 // on ChromeOS and Linux. Enabled by default.
 BASE_FEATURE(kSharedImageStubHighPriority, base::FEATURE_DISABLED_BY_DEFAULT);
@@ -122,7 +122,8 @@ BASE_FEATURE(kDefaultEnableGpuRasterization,
 // Android and Linux.
 BASE_FEATURE(kDefaultEnableGpuRasterization,
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
+    BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -450,7 +451,7 @@ const base::FeatureParam<int> kGPUDriverBugListTestGro
 const base::FeatureParam<int> kGPUDriverBugListTestGroupId{
     &kGPUDriverBugListTestGroup, "test_group", 0};
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsForceEnableWebGpuInterop() {
   return base::FeatureList::IsEnabled(kForceEnableWebGpuInterop);
 }
