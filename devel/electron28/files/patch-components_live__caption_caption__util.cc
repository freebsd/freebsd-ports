--- components/live_caption/caption_util.cc.orig	2023-08-10 01:48:40 UTC
+++ components/live_caption/caption_util.cc
@@ -145,7 +145,7 @@ bool IsLiveCaptionFeatureSupported() {
     return false;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Check if the CPU has the required instruction set to run the Speech
   // On-Device API (SODA) library.
   static bool has_sse41 = base::CPU().has_sse41();
@@ -167,7 +167,7 @@ std::string GetCaptionSettingsUrl() {
   return "chrome://os-settings/audioAndCaptions";
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "chrome://settings/captions";
 #endif  // BUILDFLAG(IS_LINUX)
 
