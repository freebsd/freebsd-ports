--- third_party/libsync/src/include/ndk/sync.h.orig	2026-04-28 21:06:17 UTC
+++ third_party/libsync/src/include/ndk/sync.h
@@ -28,6 +28,7 @@
 
 #include <stdint.h>
 
+#if 0 
 #include <linux/sync_file.h>
 
 __BEGIN_DECLS
@@ -93,7 +94,7 @@ __END_DECLS
 #endif // __ANDROID_API__ >= __ANDROID_API_O__
 
 __END_DECLS
-
+#endif
 #endif /* ANDROID_SYNC_H */
 
 /** @} */
