--- media/base/media_switches.h.orig	2022-05-19 05:17:44 UTC
+++ media/base/media_switches.h
@@ -186,7 +186,7 @@ MEDIA_EXPORT extern const base::Feature kUseDecoderStr
 MEDIA_EXPORT extern const base::Feature kUseFakeDeviceForMediaStream;
 MEDIA_EXPORT extern const base::Feature kUseMediaHistoryStore;
 MEDIA_EXPORT extern const base::Feature kUseR16Texture;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT extern const base::Feature kVaapiVideoDecodeLinux;
 MEDIA_EXPORT extern const base::Feature kVaapiVideoEncodeLinux;
 #endif  // BUILDFLAG(IS_LINUX)
