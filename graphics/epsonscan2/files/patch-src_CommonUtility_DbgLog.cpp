--- src/CommonUtility/DbgLog.cpp.orig	2021-11-25 00:56:55 UTC
+++ src/CommonUtility/DbgLog.cpp
@@ -34,6 +34,9 @@
 #ifdef __ANDROID__
 #include <android/log.h>
 #endif
+#if __FreeBSD__
+#include <pthread_np.h>
+#endif
 #if TARGET_OS_IPHONE
 #include <CoreFoundation/CoreFoundation.h>
 #endif
@@ -87,6 +90,8 @@ GetCurrentThreadId(void)
 {
 #if TARGET_OS_IPHONE
     return (DWORD)pthread_mach_thread_np(pthread_self());
+#elif __FreeBSD__
+ return pthread_getthreadid_np();
 #else
  return syscall(SYS_gettid);
 #endif
