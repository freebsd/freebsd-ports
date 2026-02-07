--- src/Util.cpp.orig	2022-01-22 10:03:14 UTC
+++ src/Util.cpp
@@ -32,6 +32,11 @@
 #include <linux/limits.h>  // For PATH_MAX
 #include <ucontext.h>      // For swapcontext
 #endif
+#ifdef __FreeBSD__
+#define CAN_GET_RUNNING_PROGRAM_NAME
+#include <sys/limits.h>  // For PATH_MAX
+#include <ucontext.h>      // For swapcontext
+#endif
 #if defined(_MSC_VER) && !defined(NOMINMAX)
 #define NOMINMAX
 #endif
@@ -141,6 +146,8 @@ string running_program_name() {
     uint32_t size = sizeof(path);
 #if defined(__linux__)
     ssize_t len = ::readlink("/proc/self/exe", path, size - 1);
+#elif defined(__FreeBSD__)
+    ssize_t len = ::readlink("/proc/curproc/file", path, size - 1);
 #elif defined(__APPLE__)
     ssize_t len = ::_NSGetExecutablePath(path, &size);
 #endif
