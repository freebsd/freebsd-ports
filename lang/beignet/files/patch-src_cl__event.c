--- src/cl_event.c.orig	2016-08-23 12:16:02.000000000 +0200
+++ src/cl_event.c	2016-08-31 17:43:49.430217000 +0200
@@ -27,6 +27,7 @@
 
 #include <assert.h>
 #include <stdio.h>
+#include <time.h>
 
 void cl_event_update_last_events(cl_command_queue queue, int wait)
 {
@@ -657,7 +658,7 @@ cl_ulong cl_event_get_cpu_timestamp(cl_u
 {
   struct timespec ts;
 
- if(clock_gettime(CLOCK_MONOTONIC_RAW,&ts) != 0){
+ if(clock_gettime(CLOCK_MONOTONIC,&ts) != 0){
   printf("CPU Timmer error\n");
   return CL_FALSE;
   }
