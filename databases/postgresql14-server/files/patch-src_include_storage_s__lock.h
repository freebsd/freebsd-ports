--- src/include/storage/s_lock.h.orig	2021-04-15 09:05:25 UTC
+++ src/include/storage/s_lock.h
@@ -320,7 +320,7 @@ tas(volatile slock_t *lock)
  * We use the int-width variant of the builtin because it works on more chips
  * than other widths.
  */
-#if defined(__arm__) || defined(__arm) || defined(__aarch64__) || defined(__aarch64)
+#if defined(__arm__) || defined(__arm) || defined(__aarch64__) || defined(__aarch64) || defined(__riscv)
 #ifdef HAVE_GCC__SYNC_INT32_TAS
 #define HAS_TEST_AND_SET
 
@@ -337,7 +337,7 @@ tas(volatile slock_t *lock)
 #define S_UNLOCK(lock) __sync_lock_release(lock)
 
 #endif	 /* HAVE_GCC__SYNC_INT32_TAS */
-#endif	 /* __arm__ || __arm || __aarch64__ || __aarch64 */
+#endif	 /* __arm__ || __arm || __aarch64__ || __aarch64 || __riscv */
 
 
 /* S/390 and S/390x Linux (32- and 64-bit zSeries) */
