--- src/osgEarth/ThreadingUtils.cpp.orig	2016-02-10 18:21:28 UTC
+++ src/osgEarth/ThreadingUtils.cpp
@@ -23,6 +23,7 @@
 #else
 #   include <unistd.h>
 #   include <sys/syscall.h>
+#   include <sys/thr.h>
 #endif
 
 using namespace osgEarth::Threading;
@@ -40,6 +41,10 @@ unsigned osgEarth::Threading::getCurrent
   return ::syscall(SYS_thread_selfid);
 #elif __ANDROID__
   return gettid();
+#elif __FreeBSD__
+  long lwpid;
+  thr_self(&lwpid);
+  return lwpid;
 #else
   return (unsigned)::syscall(SYS_gettid);
 #endif
