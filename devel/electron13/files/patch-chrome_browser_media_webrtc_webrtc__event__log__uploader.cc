--- chrome/browser/media/webrtc/webrtc_event_log_uploader.cc.orig	2021-04-14 01:08:40 UTC
+++ chrome/browser/media/webrtc/webrtc_event_log_uploader.cc
@@ -41,6 +41,8 @@ const char kProduct[] = "Chrome_Mac";
 const char kProduct[] = "Chrome_ChromeOS";
 #elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
 const char kProduct[] = "Chrome_Linux";
+#elif defined(OS_FREEBSD)
+const char kProduct[] = "Chrome_FreeBSD";
 #elif defined(OS_ANDROID)
 const char kProduct[] = "Chrome_Android";
 #else
