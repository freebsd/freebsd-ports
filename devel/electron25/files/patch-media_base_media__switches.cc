--- media/base/media_switches.cc.orig	2023-05-25 00:41:58 UTC
+++ media/base/media_switches.cc
@@ -15,7 +15,7 @@
 #include "gpu/config/gpu_finch_features.h"
 #include "media/media_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/cpu.h"
 #endif
 
@@ -620,7 +620,7 @@ BASE_FEATURE(kFallbackAfterDecodeError,
 // Show toolbar button that opens dialog for controlling media sessions.
 BASE_FEATURE(kGlobalMediaControls,
              "GlobalMediaControls",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -668,7 +668,7 @@ constexpr base::FeatureParam<kCrosGlobalMediaControlsP
 BASE_FEATURE(kGlobalMediaControlsPictureInPicture,
              "GlobalMediaControlsPictureInPicture",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -712,7 +712,7 @@ BASE_FEATURE(kUnifiedAutoplay,
              "UnifiedAutoplay",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enable vaapi video decoding on linux. This is already enabled by default on
 // chromeos, but needs an experiment on linux.
 BASE_FEATURE(kVaapiVideoDecodeLinux,
@@ -1248,7 +1248,7 @@ const base::Feature MEDIA_EXPORT kUseOutOfProcessVideo
     "UseOutOfProcessVideoDecoding", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif  // BUILDFLAG(ALLOW_OOP_VIDEO_DECODER)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Spawn utility processes to perform hardware encode acceleration instead of
 // using the GPU process.
 const base::Feature MEDIA_EXPORT kUseOutOfProcessVideoEncoding{
