--- media/base/media_switches.cc.orig	2026-11-20 03:52:43 UTC
+++ media/base/media_switches.cc
@@ -20,7 +20,7 @@
 #include "ui/gl/gl_features.h"
 #include "ui/gl/gl_utils.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/cpu.h"
 #include "components/system_media_controls/linux/buildflags/buildflags.h"
 #endif
@@ -472,13 +472,35 @@ BASE_FEATURE(kApplicationAudioCaptureMac, base::FEATUR
 
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables system audio mirroring using pulseaudio.
 BASE_FEATURE(kPulseaudioLoopbackForCast, base::FEATURE_DISABLED_BY_DEFAULT);
 
 // Enables system audio sharing using pulseaudio.
 BASE_FEATURE(kPulseaudioLoopbackForScreenShare,
              base::FEATURE_DISABLED_BY_DEFAULT);
+
+BASE_FEATURE(kAudioBackend,
+             "AudioBackend",
+             base::FEATURE_ENABLED_BY_DEFAULT);
+
+constexpr base::FeatureParam<AudioBackend>::Option
+    kAudioBackendOptions[] = {
+        {AudioBackend::kAuto,
+         "auto"},
+        {AudioBackend::kPulseAudio, "pulseaudio"},
+        {AudioBackend::kSndio, "sndio"},
+        {AudioBackend::kAlsa, "alsa"}};
+
+const base::FeatureParam<AudioBackend>
+    kAudioBackendParam{
+        &kAudioBackend, "audio-backend",
+#if BUILDFLAG(IS_OPENBSD)
+        AudioBackend::kSndio,
+#elif BUILDFLAG(IS_FREEBSD)
+        AudioBackend::kAuto,
+#endif
+        &kAudioBackendOptions};
 #endif  // BUILDFLAG(IS_LINUX)
 
 // When enabled, MediaCapabilities will check with GPU Video Accelerator
@@ -650,7 +672,7 @@ BASE_FEATURE(kSymphoniaAudioDecoding,
 // Android / Fuchsia are expected to launch in M150.
 BASE_FEATURE(kSymphoniaAudioDecoding,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -660,7 +682,7 @@ BASE_FEATURE(kSymphoniaMp3Decoding,
 // Android / Fuchsia are expected to launch in M150.
 BASE_FEATURE(kSymphoniaMp3Decoding,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -789,7 +811,7 @@ BASE_FEATURE(kMediaRemotingWithoutFullscreen,
 #if !BUILDFLAG(IS_ANDROID)
 // If enabled, users can request Media Remoting without fullscreen-in-tab.
 BASE_FEATURE(kMediaRemotingWithoutFullscreen,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -808,7 +830,7 @@ BASE_FEATURE(kUnifiedAutoplay, base::FEATURE_ENABLED_B
 // autoplay policy.
 BASE_FEATURE(kUnifiedAutoplay, base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // Enable vaapi/v4l2 video decoding on linux. This is already enabled by default
 // on chromeos, but needs an experiment on linux.
@@ -894,7 +916,7 @@ BASE_FEATURE(kVSyncMjpegDecoding, base::FEATURE_DISABL
 // Enables VSync aligned MJPEG decoding.
 BASE_FEATURE(kVSyncMjpegDecoding, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // defined(ARCH_CPU_X86_FAMILY) && BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enable H264 temporal layer encoding with V4L2 HW encoder on ChromeOS.
 BASE_FEATURE(kV4L2H264TemporalLayerHWEncoding,
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -1106,7 +1128,7 @@ BASE_FEATURE(kHardwareMediaKeyHandling,
 BASE_FEATURE(kHardwareMediaKeyHandling,
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
              base::FEATURE_ENABLED_BY_DEFAULT
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(USE_MPRIS)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -1464,7 +1486,7 @@ BASE_FEATURE(kUseSharedImageInOOPVDProcess, base::FEAT
 BASE_FEATURE(kUseSharedImageInOOPVDProcess, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(ALLOW_OOP_VIDEO_DECODER)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Spawn utility processes to perform hardware encode acceleration instead of
 // using the GPU process.
 BASE_FEATURE(kUseOutOfProcessVideoEncoding, base::FEATURE_DISABLED_BY_DEFAULT);
@@ -1526,7 +1548,7 @@ BASE_FEATURE(kRecordWebAudioEngagement, base::FEATURE_
 // Enables Media Engagement Index recording for Web Audio playbacks.
 BASE_FEATURE(kRecordWebAudioEngagement, base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Reduces the number of buffers needed in the output video frame pool to
 // populate the Renderer pipeline for hardware accelerated VideoDecoder in
 // non-low latency scenarios.
@@ -1851,7 +1873,7 @@ bool IsSystemLoopbackCaptureSupported() {
 #elif BUILDFLAG(IS_MAC)
   return (IsMacSckSystemLoopbackCaptureSupported() ||
           IsMacCatapSystemLoopbackCaptureSupported());
-#elif BUILDFLAG(IS_LINUX) && defined(USE_PULSEAUDIO)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(USE_PULSEAUDIO)
   return true;
 #else
   return false;
