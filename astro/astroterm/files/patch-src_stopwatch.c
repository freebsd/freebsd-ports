--- src/stopwatch.c.orig	2025-02-09 19:38:25 UTC
+++ src/stopwatch.c
@@ -34,7 +34,7 @@ int sw_gettime(struct SwTimestamp *stamp)
 #elif defined(__APPLE__) && defined(__MACH__)
     // Apple OSX and iOS (Darwin)
 
-    unsigned long long tick = clock_gettime_nsec_np(CLOCK_MONOTONIC_RAW);
+    unsigned long long tick = clock_gettime_nsec_np(CLOCK_MONOTONIC);
     if (tick == 0)
     {
         return -1;
@@ -47,7 +47,7 @@ int sw_gettime(struct SwTimestamp *stamp)
     // Available on some POSIX systems (preferable to gettimeofday() below)
 
     struct timespec tick;
-    int check = clock_gettime(CLOCK_MONOTONIC_RAW, &tick);
+    int check = clock_gettime(CLOCK_MONOTONIC, &tick);
     if (check == -1)
     {
         return -1;
