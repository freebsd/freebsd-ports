--- native/jsvc-unix.c.orig	2012-02-24 00:24:02.000000000 +0100
+++ native/jsvc-unix.c	2012-03-26 14:14:26.000000000 +0200
@@ -801,11 +801,11 @@ static int child(arg_data *args, home_da
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
@@ -824,7 +824,7 @@ static int child(arg_data *args, home_da
         return 6;
 
     if (doreload == true)
-        ret = 123;
+        ret = 124;
     else
         ret = 0;
 
@@ -1212,12 +1212,12 @@ static int run_controller(arg_data *args
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
