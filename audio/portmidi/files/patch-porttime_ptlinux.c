--- porttime/ptlinux.c.orig	2025-06-24 04:57:11 UTC
+++ porttime/ptlinux.c
@@ -29,7 +29,7 @@ CHANGE LOG
 #include <unistd.h>
 #include <sys/types.h>
 #include "porttime.h"
-#include "time.h"
+#include <time.h>
 #include "sys/resource.h"
 #include "pthread.h"
 
@@ -83,7 +83,7 @@ PtError Pt_Start(int resolution, PtCallback *callback,
 {
     if (time_started_flag) return ptNoError;
     /* need this set before process runs: */
-    clock_gettime(CLOCK_MONOTONIC_RAW, &time_offset);
+    clock_gettime(CLOCK_MONOTONIC_FAST, &time_offset);
     if (callback) {
         int res;
         pt_callback_parameters *parms = (pt_callback_parameters *)
@@ -126,7 +126,7 @@ PtTimestamp Pt_Time(void)
 {
     long seconds, ms;
     struct timespec now;
-    clock_gettime(CLOCK_MONOTONIC_RAW, &now);
+    clock_gettime(CLOCK_MONOTONIC_FAST, &now);
     seconds = now.tv_sec - time_offset.tv_sec;
     ms = (now.tv_nsec - time_offset.tv_nsec) / 1000000; /* round down */
     return seconds * 1000 + ms;
