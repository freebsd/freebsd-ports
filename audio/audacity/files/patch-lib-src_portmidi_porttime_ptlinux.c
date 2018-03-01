--- lib-src/portmidi/porttime/ptlinux.c.orig	2018-02-22 17:57:15.438232000 -0800
+++ lib-src/portmidi/porttime/ptlinux.c	2018-02-22 19:12:15.820418000 -0800
@@ -31,14 +31,13 @@
 #include "porttime.h"
 #include "sys/time.h"
 #include "sys/resource.h"
-#include "sys/timeb.h"
 #include "pthread.h"
 
 #define TRUE 1
 #define FALSE 0
 
 static int time_started_flag = FALSE;
-static struct timeb time_offset = {0, 0, 0, 0};
+static struct timeval time_offset = {0};
 static pthread_t pt_thread_pid;
 static int pt_thread_created = FALSE;
 
@@ -79,7 +78,7 @@
 PtError Pt_Start(int resolution, PtCallback *callback, void *userData)
 {
     if (time_started_flag) return ptNoError;
-    ftime(&time_offset); /* need this set before process runs */
+    gettimeofday(&time_offset, 0);
     if (callback) {
         int res;
         pt_callback_parameters *parms = (pt_callback_parameters *) 
@@ -121,10 +120,10 @@
 PtTimestamp Pt_Time()
 {
     long seconds, milliseconds;
-    struct timeb now;
-    ftime(&now);
-    seconds = now.time - time_offset.time;
-    milliseconds = now.millitm - time_offset.millitm;
+    struct timeval now;
+    gettimeofday(&now, 0);
+    seconds = now.tv_sec - time_offset.tv_sec;
+    milliseconds = (now.tv_usec / 1000) - (time_offset.tv_usec / 1000);
     return seconds * 1000 + milliseconds;
 }
 
