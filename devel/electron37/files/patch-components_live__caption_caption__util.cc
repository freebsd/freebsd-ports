--- components/live_caption/caption_util.cc.orig	2025-06-30 07:04:30 UTC
+++ components/live_caption/caption_util.cc
@@ -141,7 +141,7 @@ std::string GetCaptionSettingsUrl() {
 std::string GetCaptionSettingsUrl() {
 #if BUILDFLAG(IS_CHROMEOS)
   return "chrome://os-settings/audioAndCaptions";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "chrome://settings/captions";
 #elif BUILDFLAG(IS_WIN)
   return base::win::GetVersion() >= base::win::Version::WIN10
