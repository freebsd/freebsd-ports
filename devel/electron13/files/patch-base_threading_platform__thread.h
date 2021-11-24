--- base/threading/platform_thread.h.orig	2021-04-14 01:08:36 UTC
+++ base/threading/platform_thread.h
@@ -231,7 +231,7 @@ class BASE_EXPORT PlatformThread {
   // Returns a realtime period provided by |delegate|.
   static TimeDelta GetRealtimePeriod(Delegate* delegate);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Toggles a specific thread's priority at runtime. This can be used to
   // change the priority of a thread in a different process and will fail
   // if the calling process does not have proper permissions. The
