--- chrome/browser/media/webrtc/webrtc_event_log_uploader.cc.orig	2023-08-10 01:48:35 UTC
+++ chrome/browser/media/webrtc/webrtc_event_log_uploader.cc
@@ -42,7 +42,7 @@ const char kProduct[] = "Chrome";
 const char kProduct[] = "Chrome_Mac";
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
 const char kProduct[] = "Chrome_ChromeOS";
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 const char kProduct[] = "Chrome_Linux";
 #elif BUILDFLAG(IS_ANDROID)
 const char kProduct[] = "Chrome_Android";
