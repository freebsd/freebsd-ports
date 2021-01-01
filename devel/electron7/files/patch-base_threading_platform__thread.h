--- base/threading/platform_thread.h.orig	2019-12-12 12:38:59 UTC
+++ base/threading/platform_thread.h
@@ -221,7 +221,7 @@ class BASE_EXPORT PlatformThread {
 
   static ThreadPriority GetCurrentThreadPriority();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Toggles a specific thread's priority at runtime. This can be used to
   // change the priority of a thread in a different process and will fail
   // if the calling process does not have proper permissions. The
