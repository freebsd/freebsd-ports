--- src/avro/refcount.h.orig	2017-04-17 23:56:17 UTC
+++ src/avro/refcount.h
@@ -118,7 +118,7 @@ avro_refcount_dec(volatile int *refcount
  * GCC intrinsics
  */
 
-#elif (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__) > 40500
+#elif (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__) > 40500 || defined(__clang__)
 
 static inline void
 avro_refcount_set(volatile int *refcount, int value)
