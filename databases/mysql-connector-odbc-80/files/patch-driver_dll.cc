--- driver/dll.cc.orig	2022-12-10 21:58:26 UTC
+++ driver/dll.cc
@@ -145,7 +145,7 @@ void myodbc_end()
        This eliminates the delay when mysys_end() is called and other threads
        have been initialized but not ended.
     */
-    my_thread_end_wait_time= 0;
+    static uint my_thread_end_wait_time= 0;
 #endif
 
     mysql_library_end();
