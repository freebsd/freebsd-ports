--- src/cl_event.c.orig	2015-09-24 02:49:06 UTC
+++ src/cl_event.c
@@ -27,8 +27,9 @@
 
 #include <assert.h>
 #include <stdio.h>
+#include <time.h>
 
-inline cl_bool
+static inline cl_bool
 cl_event_is_gpu_command_type(cl_command_type type)
 {
   switch(type) {
@@ -617,7 +618,7 @@ cl_ulong cl_event_get_cpu_timestamp(cl_u
 {
   struct timespec ts;
 
- if(clock_gettime(CLOCK_MONOTONIC_RAW,&ts) != 0){
+ if(clock_gettime(CLOCK_MONOTONIC,&ts) != 0){
   printf("CPU Timmer error\n");
   return CL_FALSE;
   }
