--- chrome/browser/tracing/crash_service_uploader.cc.orig	2019-04-08 08:32:46 UTC
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
