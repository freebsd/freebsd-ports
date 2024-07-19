--- components/viz/common/features.h.orig	2024-06-18 21:43:31 UTC
+++ components/viz/common/features.h
@@ -74,7 +74,7 @@ VIZ_COMMON_EXPORT BASE_DECLARE_FEATURE(
 VIZ_COMMON_EXPORT BASE_DECLARE_FEATURE(kAllowUndamagedNonrootRenderPassToSkip);
 VIZ_COMMON_EXPORT BASE_DECLARE_FEATURE(
     kAllowForceMergeRenderPassWithRequireOverlayQuads);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 VIZ_COMMON_EXPORT BASE_DECLARE_FEATURE(kRendererAllocatesImages);
 #endif
 VIZ_COMMON_EXPORT BASE_DECLARE_FEATURE(kBufferQueueImageSetPurgeable);
@@ -134,7 +134,7 @@ VIZ_COMMON_EXPORT bool ShouldOnBeginFrameThrottleVideo
 VIZ_COMMON_EXPORT std::optional<double> IsDynamicSchedulerEnabledForClients();
 VIZ_COMMON_EXPORT int MaxOverlaysConsidered();
 VIZ_COMMON_EXPORT bool ShouldOnBeginFrameThrottleVideo();
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 VIZ_COMMON_EXPORT bool ShouldRendererAllocateImages();
 #endif
 VIZ_COMMON_EXPORT bool IsOnBeginFrameAcksEnabled();
