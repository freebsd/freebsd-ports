--- src/CommonUtility/DbgLog.cpp.orig	2024-09-12 07:10:38 UTC
+++ src/CommonUtility/DbgLog.cpp
@@ -31,6 +31,9 @@
 #ifdef __ANDROID__
 #include <android/log.h>
 #endif
+#if __FreeBSD__
+#include <pthread_np.h>
+#endif
 #if TARGET_OS_IPHONE
 #include <CoreFoundation/CoreFoundation.h>
 #endif
@@ -84,6 +87,8 @@ GetCurrentThreadId(void)
 {
 #if TARGET_OS_IPHONE
     return (DWORD)pthread_mach_thread_np(pthread_self());
+#elif __FreeBSD__
+    return pthread_getthreadid_np();
 #else
  return syscall(SYS_gettid);
 #endif
