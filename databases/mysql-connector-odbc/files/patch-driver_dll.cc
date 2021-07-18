--- driver/dll.cc.orig	2019-04-15 16:56:34 UTC
+++ driver/dll.cc
@@ -125,7 +125,7 @@ void myodbc_end()
        This eliminates the delay when mysys_end() is called and other threads
        have been initialized but not ended.
     */
-    my_thread_end_wait_time= 0;
+    static uint my_thread_end_wait_time= 0;
 #endif
 
 /*
