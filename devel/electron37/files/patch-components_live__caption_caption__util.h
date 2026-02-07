--- components/live_caption/caption_util.h.orig	2024-04-15 20:33:54 UTC
+++ components/live_caption/caption_util.h
@@ -15,7 +15,7 @@ namespace captions {
 namespace captions {
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kCaptionSettingsUrl[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_MAC)
