--- base/logging.cpp.orig	2015-08-12 23:28:08 UTC
+++ base/logging.cpp
@@ -23,12 +23,14 @@
 #include <libgen.h>
 
 // For getprogname(3) or program_invocation_short_name.
-#if defined(__ANDROID__) || defined(__APPLE__)
+#if !defined(_WIN32) && !defined(__GLIBC__)
 #include <stdlib.h>
 #elif defined(__GLIBC__)
 #include <errno.h>
 #endif
 
+#include <cstring> // strlen
+#include <cstdio>  // fprintf
 #include <iostream>
 #include <limits>
 #include <sstream>
@@ -66,6 +68,14 @@
 #include <unistd.h>
 #elif defined(_WIN32)
 #include <windows.h>
+#elif defined(__DragonFly__)
+#include <unistd.h>
+#elif defined(__FreeBSD__)
+#include <pthread_np.h>
+#elif defined(__NetBSD__)
+#include <lwp.h>
+#else
+#include <stdint.h>
 #endif
 
 static pid_t GetThreadId() {
@@ -77,6 +89,14 @@ static pid_t GetThreadId() {
   return syscall(__NR_gettid);
 #elif defined(_WIN32)
   return GetCurrentThreadId();
+#elif defined(__DragonFly__)
+  return lwp_gettid();
+#elif defined(__NetBSD__)
+  return _lwp_self();
+#elif defined(__FreeBSD__)
+  return pthread_getthreadid_np();
+#else
+  return (intptr_t) pthread_self();
 #endif
 }
 
