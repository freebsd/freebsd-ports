--- plugins/artwork/cache.c.orig	2016-01-02 20:28:08 UTC
+++ plugins/artwork/cache.c
@@ -160,7 +160,8 @@ cache_cleaner_thread(void *none)
             usleep(100000);
             deadbeef->mutex_lock(thread_mutex);
         }
-        closedir(covers_dir);
+        if (covers_dir)
+            closedir(covers_dir);
 
         /* Sleep until just after the oldest file expires */
         if (cache_expiry_seconds > 0 && !terminate) {
