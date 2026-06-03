--- driver/dll.cc.orig	2025-06-19 12:19:21 UTC
+++ driver/dll.cc
@@ -144,7 +144,7 @@ void myodbc_end()
        This eliminates the delay when mysys_end() is called and other threads
        have been initialized but not ended.
     */
-    my_thread_end_wait_time= 0;
+    static uint my_thread_end_wait_time= 0;
 #endif
     /*
       When driver is unloaded the plugin pool must be cleared.
