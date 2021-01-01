--- chrome/browser/tracing/crash_service_uploader.cc.orig	2019-09-10 11:13:43 UTC
+++ chrome/browser/tracing/crash_service_uploader.cc
@@ -162,6 +162,8 @@ void TraceCrashServiceUploader::DoCompressOnBackground
   const char product[] = "Chrome_Linux";
 #elif defined(OS_ANDROID)
   const char product[] = "Chrome_Android";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
