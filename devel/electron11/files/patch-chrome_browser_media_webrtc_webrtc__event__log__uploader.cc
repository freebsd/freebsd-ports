--- chrome/browser/media/webrtc/webrtc_event_log_uploader.cc.orig	2021-01-07 00:36:23 UTC
+++ chrome/browser/media/webrtc/webrtc_event_log_uploader.cc
@@ -40,6 +40,8 @@ const char kProduct[] = "Chrome_Mac";
 const char kProduct[] = "Chrome_ChromeOS";
 #elif defined(OS_LINUX)
 const char kProduct[] = "Chrome_Linux";
+#elif defined(OS_FREEBSD)
+const char kProduct[] = "Chrome_FreeBSD";
 #elif defined(OS_ANDROID)
 const char kProduct[] = "Chrome_Android";
 #else
