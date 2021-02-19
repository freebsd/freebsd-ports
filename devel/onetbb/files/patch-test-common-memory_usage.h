--- test/common/memory_usage.h.orig	2020-12-08 11:00:57 UTC
+++ test/common/memory_usage.h
@@ -119,7 +119,8 @@ namespace utils {
         ASSERT(status == KERN_SUCCESS, NULL);
         return info.virtual_size - shared_size;
 #else
-        return 0;
+        // Use stat var to work around unused parameter error
+        return stat == currentUsage ? 0 : 0;
 #endif
     }
 
