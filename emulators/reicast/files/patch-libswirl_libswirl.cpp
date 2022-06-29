--- libswirl/libswirl.cpp.orig	2020-10-18 11:22:48 UTC
+++ libswirl/libswirl.cpp
@@ -95,7 +95,7 @@ int64_t get_time_usec(void)
     if (!QueryPerformanceCounter(&count))
         return 0;
     return count.QuadPart * 1000000 / freq.QuadPart;
-#elif defined(_POSIX_MONOTONIC_CLOCK) || defined(__QNX__) || defined(ANDROID) || defined(__MACH__) || HOST_OS==OS_LINUX
+#elif defined(_POSIX_MONOTONIC_CLOCK) || defined(__QNX__) || defined(ANDROID) || defined(__MACH__) || HOST_OS==OS_LINUX || HOST_OS==OS_FREEBSD
     struct timespec tv = { 0 };
     if (clock_gettime(CLOCK_MONOTONIC, &tv) < 0)
         return 0;
