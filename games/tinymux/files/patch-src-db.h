--- db.h.orig	Tue Oct 28 00:58:23 2003
+++ db.h	Tue Oct 28 00:58:46 2003
@@ -16,7 +16,7 @@
 #define STORE(key, attr, len)	cache_put(key, attr, len)
 #else
 #define STORE(key, attr)	cache_put(key, attr)
-#endif RADIX_COMPRESSION
+#endif /* RADIX_COMPRESSION */
 #define DELETE(key)		cache_del(key)
 #define FETCH(key)		cache_get(key)
 #define SYNC			cache_sync()
@@ -27,7 +27,7 @@
 #define FETCH(key)
 #define SYNC
 #define CLOSE
-#endif MEMORY_BASED
+#endif /* MEMORY_BASED */
 
 #include "udb.h"
 
