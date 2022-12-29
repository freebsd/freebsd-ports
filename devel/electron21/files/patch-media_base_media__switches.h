--- media/base/media_switches.h.orig	2022-08-31 12:19:35 UTC
+++ media/base/media_switches.h
@@ -203,7 +203,7 @@ MEDIA_EXPORT extern const base::Feature kUseDecoderStr
 MEDIA_EXPORT extern const base::Feature kUseFakeDeviceForMediaStream;
 MEDIA_EXPORT extern const base::Feature kUseMediaHistoryStore;
 MEDIA_EXPORT extern const base::Feature kUseR16Texture;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT extern const base::Feature kVaapiVideoDecodeLinux;
 MEDIA_EXPORT extern const base::Feature kVaapiVideoEncodeLinux;
 MEDIA_EXPORT extern const base::Feature kVaapiIgnoreDriverChecks;
@@ -310,7 +310,7 @@ MEDIA_EXPORT extern const base::FeatureParam<
 MEDIA_EXPORT extern const base::Feature kDeprecateLowUsageCodecs;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT extern const base::Feature kUseOutOfProcessVideoDecoding;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
