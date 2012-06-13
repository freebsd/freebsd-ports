--- native/jsvc-unix.c.orig	2012-02-24 00:24:02.000000000 +0100
+++ native/jsvc-unix.c	2012-06-13 12:40:54.000000000 +0200
@@ -621,18 +621,13 @@
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
@@ -671,7 +666,6 @@
                 }
             }
         }
-        sleep(waittime);
         count--;
     }
     /* It takes more than the wait time to start,
@@ -801,11 +795,11 @@
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
@@ -824,7 +818,7 @@
         return 6;
 
     if (doreload == true)
-        ret = 123;
+        ret = 124;
     else
         ret = 0;
 
@@ -1212,12 +1206,12 @@
             if (args->vers != true && args->chck != true && status != 122)
                 unlink(args->pidf);
 
-            /* If the child got out with 123 he wants to be restarted */
+            /* If the child got out with 123 or 124 he wants to be restarted */
             /* See java_abort123 (we use this return code to restart when the JVM aborts) */
-            if (status == 123) {
+            if (status == 123 || status == 124) {
                 log_debug("Reloading service");
                 /* prevent looping */
-                if (laststart + 60 > time(NULL)) {
+                if (status == 123 && laststart + 60 > time(NULL)) {
                     log_debug("Waiting 60 s to prevent looping");
                     sleep(60);
                 }
