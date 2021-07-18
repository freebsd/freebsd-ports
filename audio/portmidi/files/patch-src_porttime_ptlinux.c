--- src/porttime/ptlinux.c.orig	2021-07-17 02:14:06 UTC
+++ src/porttime/ptlinux.c
@@ -1,3 +1,4 @@
+
 /* ptlinux.c -- portable timer implementation for linux */
 
 
@@ -31,14 +32,14 @@ CHANGE LOG
 #include "porttime.h"
 #include "sys/time.h"
 #include "sys/resource.h"
-#include "sys/timeb.h"
 #include "pthread.h"
 
 #define TRUE 1
 #define FALSE 0
 
 static int time_started_flag = FALSE;
-static struct timeb time_offset = {0, 0, 0, 0};
+static struct timeval *time_offset;
+
 static pthread_t pt_thread_pid;
 static int pt_thread_created = FALSE;
 
@@ -79,7 +80,8 @@ static void *Pt_CallbackProc(void *p)
 PtError Pt_Start(int resolution, PtCallback *callback, void *userData)
 {
     if (time_started_flag) return ptNoError;
-    ftime(&time_offset); /* need this set before process runs */
+    gettimeofday(time_offset, NULL);
+
     if (callback) {
         int res;
         pt_callback_parameters *parms = (pt_callback_parameters *) 
@@ -121,10 +123,12 @@ int Pt_Started()
 PtTimestamp Pt_Time()
 {
     long seconds, milliseconds;
-    struct timeb now;
-    ftime(&now);
-    seconds = now.time - time_offset.time;
-    milliseconds = now.millitm - time_offset.millitm;
+    struct timeval *now;
+
+    gettimeofday(now, NULL);
+
+    seconds = now->tv_sec - time_offset->tv_sec;
+    milliseconds = now->tv_usec - time_offset->tv_usec;
     return seconds * 1000 + milliseconds;
 }
 
