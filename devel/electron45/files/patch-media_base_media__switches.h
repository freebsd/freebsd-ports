--- media/base/media_switches.h.orig	2026-11-20 12:09:56 UTC
+++ media/base/media_switches.h
@@ -450,7 +450,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kShowForceRespectUiG
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kShowForceRespectUiGainsToggle);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kReduceHardwareVideoDecoderBuffers);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseOutOfProcessVideoEncoding);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kV4L2H264TemporalLayerHWEncoding);
@@ -461,7 +461,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kFuchsiaMediacodecVi
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kFuchsiaMediacodecVideoEncoder);
 #endif  // BUILDFLAG(IS_FUCHSIA)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kAcceleratedVideoDecodeLinux);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kAcceleratedVideoDecodeLinuxGL);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kAcceleratedVideoEncodeLinux);
@@ -472,6 +472,18 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiIgnoreDriverCh
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPulseaudioLoopbackForCast);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPulseaudioLoopbackForScreenShare);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiIgnoreDriverChecks);
+
+enum class AudioBackend {
+  kAuto,
+  kPulseAudio,
+  kSndio,
+  kAlsa
+};
+
+MEDIA_EXPORT BASE_DECLARE_FEATURE(kAudioBackend);
+MEDIA_EXPORT extern const base::FeatureParam<
+    AudioBackend>
+    kAudioBackendParam;
 #endif  // BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(IS_MAC)
