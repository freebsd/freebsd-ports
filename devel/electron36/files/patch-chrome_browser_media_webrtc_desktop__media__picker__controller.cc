--- chrome/browser/media/webrtc/desktop_media_picker_controller.cc.orig	2024-06-18 21:43:22 UTC
+++ chrome/browser/media/webrtc/desktop_media_picker_controller.cc
@@ -89,7 +89,7 @@ bool DesktopMediaPickerController::IsSystemAudioCaptur
 #if BUILDFLAG(IS_MAC)
  return request_source == Params::RequestSource::kCast ||
      base::FeatureList::IsEnabled(media::kMacLoopbackAudioForScreenShare);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (request_source == Params::RequestSource::kCast) {
     return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
   } else {
