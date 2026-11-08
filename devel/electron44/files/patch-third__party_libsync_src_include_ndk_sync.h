--- third_party/libsync/src/include/ndk/sync.h.orig	2026-08-24 20:59:34 UTC
+++ third_party/libsync/src/include/ndk/sync.h
@@ -29,6 +29,7 @@
 #include <stdint.h>
 #include <sys/cdefs.h>
 
+#if 0 
 #include <linux/sync_file.h>
 
 __BEGIN_DECLS
@@ -100,7 +101,7 @@ __END_DECLS
 void sync_file_info_free(struct sync_file_info* info) __INTRODUCED_IN(26);
 
 __END_DECLS
-
+#endif
 #endif /* ANDROID_SYNC_H */
 
 /** @} */
