--- native/jsvc-unix.c.orig	2017-11-15 11:51:22 UTC
+++ native/jsvc-unix.c
@@ -717,18 +717,13 @@ static void remove_tmp_file(arg_data *ar
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
@@ -767,7 +762,6 @@ static int wait_child(arg_data *args, in
                 }
             }
         }
-        sleep(waittime);
         count--;
     }
     /* It takes more than the wait time to start,
@@ -901,11 +895,11 @@ static int child(arg_data *args, home_da
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
         if(doreopen) {
             doreopen = false;
@@ -924,7 +918,7 @@ static int child(arg_data *args, home_da
         return 6;
 
     if (doreload == true)
-        ret = 123;
+        ret = 124;
     else
         ret = 0;
 
@@ -1341,10 +1335,10 @@ static int run_controller(arg_data *args
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
@@ -1356,7 +1350,7 @@ static int run_controller(arg_data *args
                     log_debug("Reloading service");
                     restarts++;
                     /* prevent looping */
-                    if (laststart + 60 > time(NULL)) {
+                    if (status == 123 && laststart + 60 > time(NULL)) {
                         log_debug("Waiting 60 s to prevent looping");
                         sleep(60);
                     }
