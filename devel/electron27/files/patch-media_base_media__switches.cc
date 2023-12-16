--- media/base/media_switches.cc.orig	2023-10-19 19:58:26 UTC
+++ media/base/media_switches.cc
@@ -17,7 +17,7 @@
 #include "ui/gl/gl_features.h"
 #include "ui/gl/gl_utils.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/cpu.h"
 #endif
 
@@ -673,7 +673,7 @@ BASE_FEATURE(kFallbackAfterDecodeError,
 // Show toolbar button that opens dialog for controlling media sessions.
 BASE_FEATURE(kGlobalMediaControls,
              "GlobalMediaControls",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -696,7 +696,7 @@ BASE_FEATURE(kGlobalMediaControlsCrOSUpdatedUI,
 // If enabled, users can request Media Remoting without fullscreen-in-tab.
 BASE_FEATURE(kMediaRemotingWithoutFullscreen,
              "MediaRemotingWithoutFullscreen",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -708,7 +708,7 @@ BASE_FEATURE(kMediaRemotingWithoutFullscreen,
 BASE_FEATURE(kGlobalMediaControlsPictureInPicture,
              "GlobalMediaControlsPictureInPicture",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -752,7 +752,7 @@ BASE_FEATURE(kUnifiedAutoplay,
              "UnifiedAutoplay",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enable vaapi video decoding on linux. This is already enabled by default on
 // chromeos, but needs an experiment on linux.
 BASE_FEATURE(kVaapiVideoDecodeLinux,
@@ -832,7 +832,7 @@ BASE_FEATURE(kVaapiVp9kSVCHWEncoding,
              "VaapiVp9kSVCHWEncoding",
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // defined(ARCH_CPU_X86_FAMILY) && BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables the new V4L2StatefulVideoDecoder instead of V4L2VideoDecoder.
 BASE_FEATURE(kV4L2FlatStatelessVideoDecoder,
              "V4L2FlatStatelessVideoDecoder",
@@ -1348,7 +1348,7 @@ const base::Feature MEDIA_EXPORT kUseOutOfProcessVideo
 };
 #endif  // BUILDFLAG(ALLOW_OOP_VIDEO_DECODER)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Spawn utility processes to perform hardware encode acceleration instead of
 // using the GPU process.
 const base::Feature MEDIA_EXPORT kUseOutOfProcessVideoEncoding{
