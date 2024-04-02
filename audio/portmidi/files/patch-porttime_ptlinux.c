--- porttime/ptlinux.c.orig	2024-04-01 19:43:35.367808000 +0200
+++ porttime/ptlinux.c	2024-04-01 19:43:57.157503000 +0200
@@ -29,9 +29,8 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include "porttime.h"
-#include "time.h"
+#include <time.h>
 #include "sys/resource.h"
-#include "sys/timeb.h"
 #include "pthread.h"
 
 #define TRUE 1
@@ -80,7 +79,7 @@
 {
     if (time_started_flag) return ptNoError;
     /* need this set before process runs: */
-    clock_gettime(CLOCK_MONOTONIC_RAW, &time_offset);
+    clock_gettime(CLOCK_MONOTONIC_FAST, &time_offset);
     if (callback) {
         int res;
         pt_callback_parameters *parms = (pt_callback_parameters *) 
@@ -123,7 +122,7 @@
 {
     long seconds, ms;
     struct timespec now;
-    clock_gettime(CLOCK_MONOTONIC_RAW, &now);
+    clock_gettime(CLOCK_MONOTONIC_FAST, &now);
     seconds = now.tv_sec - time_offset.tv_sec;
     ms = (now.tv_nsec - time_offset.tv_nsec) / 1000000; /* round down */
     return seconds * 1000 + ms;
