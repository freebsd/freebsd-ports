--- libs/Common/Types.h.orig	2022-04-17 08:46:34 UTC
+++ libs/Common/Types.h
@@ -201,6 +201,9 @@ namespace cv { namespace gpu = cuda; }
 # elif defined(__APPLE__)
 #  include <pthread.h>
 inline pid_t GetCurrentThreadId() { uint64_t tid64; pthread_threadid_np(NULL, &tid64); return (pid_t)tid64; }
+# elif defined(__FreeBSD__)
+#  include <pthread.h>
+inline pid_t GetCurrentThreadId() { uint64_t tid64 = (uint64_t)pthread_self(); return (pid_t)tid64; }
 #  define __THREAD__ ((unsigned)GetCurrentThreadId())
 # else
 #  include <sys/syscall.h>
@@ -373,6 +376,8 @@ typedef TAliasCast<double,int32_t> CastD2I;
 # define __BYTE_ORDER __LITTLE_ENDIAN
 #elif defined(__APPLE__)
 # include <machine/endian.h>
+#elif defined(__FreeBSD__)
+# include <sys/endian.h>
 #elif defined(__GNUC__)
 # include <endian.h>
 #endif
