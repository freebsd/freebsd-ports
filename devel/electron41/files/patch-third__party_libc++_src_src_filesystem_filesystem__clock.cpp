--- third_party/libc++/src/src/filesystem/filesystem_clock.cpp.orig	2025-08-26 20:49:50 UTC
+++ third_party/libc++/src/src/filesystem/filesystem_clock.cpp
@@ -37,7 +37,7 @@
 #endif
 
 #if defined(__APPLE__) || defined(__gnu_hurd__) || defined(__AMDGPU__) || defined(__NVPTX__) ||                        \
-    (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0)
+    (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #  define _LIBCPP_HAS_CLOCK_GETTIME
 #endif
 
