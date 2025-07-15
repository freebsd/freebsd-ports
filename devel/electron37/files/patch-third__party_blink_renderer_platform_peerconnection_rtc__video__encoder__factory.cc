--- third_party/blink/renderer/platform/peerconnection/rtc_video_encoder_factory.cc.orig	2025-04-22 20:15:27 UTC
+++ third_party/blink/renderer/platform/peerconnection/rtc_video_encoder_factory.cc
@@ -324,12 +324,12 @@ SupportedFormats GetSupportedFormatsInternal(
       supported_formats.profiles.push_back(profile.profile);
       supported_formats.sdp_formats.push_back(std::move(*format));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_WIN)
       const bool kShouldAddH264Cbp =
           base::FeatureList::IsEnabled(kMediaFoundationH264CbpEncoding) &&
           profile.profile == media::VideoCodecProfile::H264PROFILE_BASELINE;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       const bool kShouldAddH264Cbp =
           profile.profile == media::VideoCodecProfile::H264PROFILE_BASELINE;
 #endif
