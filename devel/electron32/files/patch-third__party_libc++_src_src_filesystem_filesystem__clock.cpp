--- third_party/libc++/src/src/filesystem/filesystem_clock.cpp.orig	2024-02-21 00:21:25 UTC
+++ third_party/libc++/src/src/filesystem/filesystem_clock.cpp
@@ -29,7 +29,7 @@
 #  include <sys/time.h> // for gettimeofday and timeval
 #endif
 
-#if defined(__APPLE__) || defined(__gnu_hurd__) || (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0)
+#if defined(__APPLE__) || defined(__gnu_hurd__) || (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #  define _LIBCPP_HAS_CLOCK_GETTIME
 #endif
 
