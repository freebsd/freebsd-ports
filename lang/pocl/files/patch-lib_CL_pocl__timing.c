--- lib/CL/pocl_timing.c.orig	2025-05-21 11:53:16 UTC
+++ lib/CL/pocl_timing.c
@@ -74,8 +74,8 @@ uint64_t pocl_gettimemono_ns() {
   struct timespec timespec;
 # ifdef CLOCK_MONOTONIC_RAW /* Linux */
   clock_gettime(CLOCK_MONOTONIC_RAW, &timespec);
-# elif defined(CLOCK_UPTIME_FAST) /* FreeBSD, DragonFlyBSD, etc */
-  clock_gettime(CLOCK_UPTIME_FAST, &timespec);
+# elif defined(CLOCK_MONOTONIC_FAST) /* FreeBSD, DragonFlyBSD, etc */
+  clock_gettime(CLOCK_MONOTONIC_FAST, &timespec);
 # elif defined(CLOCK_MONOTONIC) /* POSIX 2008, NetBSD, etc */
   clock_gettime(CLOCK_MONOTONIC, &timespec);
 # else /* older POSIX didn't define CLOCK_MONOTONIC */
