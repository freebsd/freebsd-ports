--- chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2023-05-25 00:41:43 UTC
+++ chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -372,6 +372,10 @@ void WebRtcLogUploader::SetupMultipart(
   const char product[] = "Chrome_ChromeOS";
 #elif BUILDFLAG(IS_FUCHSIA)
   const char product[] = "Chrome_Fuchsia";
+#elif defined(OS_OPENBSD)
+  const char product[] = "Chrome_OpenBSD";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
