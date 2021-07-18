--- src/tbb/tools_api/ittnotify_config.h.orig	2021-06-30 18:42:09 UTC
+++ src/tbb/tools_api/ittnotify_config.h
@@ -335,7 +335,7 @@ ITT_INLINE long
 __itt_interlocked_increment(volatile long* ptr) ITT_INLINE_ATTRIBUTE;
 ITT_INLINE long __itt_interlocked_increment(volatile long* ptr)
 {
-    return __TBB_machine_fetchadd4(ptr, 1) + 1L;
+    return __atomic_fetch_add(ptr, 1L, __ATOMIC_SEQ_CST) + 1L;
 }
 #endif /* ITT_SIMPLE_INIT */
 
