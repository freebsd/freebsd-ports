--- third_party/blink/renderer/platform/peerconnection/rtc_video_encoder_factory.cc.orig	2024-06-18 21:43:41 UTC
+++ third_party/blink/renderer/platform/peerconnection/rtc_video_encoder_factory.cc
@@ -285,12 +285,12 @@ SupportedFormats GetSupportedFormatsInternal(
       supported_formats.scalability_modes.push_back(profile.scalability_modes);
       supported_formats.sdp_formats.push_back(std::move(*format));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_WIN)
       const bool kShouldAddH264Cbp =
           base::FeatureList::IsEnabled(kMediaFoundationH264CbpEncoding) &&
           profile.profile == media::VideoCodecProfile::H264PROFILE_BASELINE;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       const bool kShouldAddH264Cbp =
           profile.profile == media::VideoCodecProfile::H264PROFILE_BASELINE;
 #endif
