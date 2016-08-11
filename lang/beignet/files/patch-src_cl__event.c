--- src/cl_event.c.orig	2015-12-18 07:57:09.000000000 +0100
+++ src/cl_event.c	2016-05-21 00:04:34.412251000 +0200
@@ -27,6 +27,7 @@
 
 #include <assert.h>
 #include <stdio.h>
+#include <time.h>
 
 void cl_event_update_last_events(cl_command_queue queue, int wait)
 {
@@ -55,7 +56,7 @@ void cl_event_insert_last_events(cl_comm
   else set_last_event(queue,event);
 }
 
-inline cl_bool
+static inline cl_bool
 cl_event_is_gpu_command_type(cl_command_type type)
 {
   switch(type) {
@@ -649,7 +650,7 @@ cl_ulong cl_event_get_cpu_timestamp(cl_u
 {
   struct timespec ts;
 
- if(clock_gettime(CLOCK_MONOTONIC_RAW,&ts) != 0){
+ if(clock_gettime(CLOCK_MONOTONIC,&ts) != 0){
   printf("CPU Timmer error\n");
   return CL_FALSE;
   }
