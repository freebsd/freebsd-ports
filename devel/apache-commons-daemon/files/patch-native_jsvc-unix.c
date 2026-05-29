--- native/jsvc-unix.c.orig	2025-12-11 12:00:00 UTC
+++ native/jsvc-unix.c
@@ -755,18 +756,13 @@ static int wait_child(arg_data *args, int pid)
  */
 static int wait_child(arg_data *args, int pid)
 {
-    int count = 10;
+    int count = args->wait;
     bool havejvm = false;
     int fd;
     char buff[80];
-    int i, status, waittime;
+    int i, status;
 
     log_debug("wait_child %d", pid);
-    waittime = args->wait / 10;
-    if (waittime > 10) {
-        count = waittime;
-        waittime = 10;
-    }
     while (count > 0) {
         sleep(1);
         /* check if the controler is still running */
@@ -812,7 +808,6 @@ static int wait_child(arg_data *args, int pid)
                 }
             }
         }
-        sleep(waittime);
         count--;
     }
     /* It takes more than the wait time to start,
@@ -946,11 +941,11 @@ static int child(arg_data *args, home_data *data, uid_
     create_tmp_file(args);
     while (!stopping) {
 #if defined(OSD_POSIX)
-        java_sleep(60);
+        java_sleep(1);
         /* pause(); */
 #else
         /* pause() is not threadsafe */
-        sleep(60);
+        sleep(1);
 #endif
         if (doreopen) {
             doreopen = false;
@@ -969,7 +964,7 @@ static int child(arg_data *args, home_data *data, uid_
         return 6;
 
     if (doreload == true)
-        ret = 123;
+        ret = 124;
     else
         ret = 0;
 
@@ -1385,10 +1380,10 @@ static int run_controller(arg_data *args, home_data *d
             if (args->vers != true && args->chck != true && status != 122)
                 remove_pid_file(args, pid);
 
-            /* If the child got out with 123 he wants to be restarted */
+            /* If the child got out with 123 or 124 he wants to be restarted */
             /* See java_abort123 (we use this return code to restart when the JVM aborts) */
             if (!stopping) {
-                if (status == 123) {
+                if (status == 123 || status == 124) {
                     if (args->restarts == 0) {
                         log_debug("Service failure, restarts disabled");
                         return 1;
@@ -1400,7 +1395,7 @@ static int run_controller(arg_data *args, home_data *d
                     log_debug("Reloading service");
                     restarts++;
                     /* prevent looping */
-                    if (laststart + 60 > time(NULL)) {
+                    if (status == 123 && laststart + 60 > time(NULL)) {
                         log_debug("Waiting 60 s to prevent looping");
                         sleep(60);
                     }
