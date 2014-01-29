--- src/osgEarth/ThreadingUtils.cpp.orig	2013-05-16 20:29:30.000000000 +0200
+++ src/osgEarth/ThreadingUtils.cpp	2013-05-16 20:28:01.000000000 +0200
@@ -23,6 +23,7 @@
 #else
 #   include <unistd.h>
 #   include <sys/syscall.h>
+#   include <sys/thr.h>
 #endif
 
 using namespace osgEarth::Threading;
@@ -38,6 +39,10 @@
   return (unsigned)::GetCurrentThreadId();
 #elif __APPLE__
   return ::syscall(SYS_thread_selfid);
+#elif __FreeBSD__
+  long lwpid;
+  thr_self(&lwpid);
+  return lwpid;
 #else
   return (unsigned)::syscall(SYS_gettid);
 #endif
