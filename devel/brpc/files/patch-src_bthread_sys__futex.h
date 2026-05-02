--- src/bthread/sys_futex.h.orig	2026-02-23 02:11:29 UTC
+++ src/bthread/sys_futex.h
@@ -53,7 +53,7 @@ inline int futex_requeue_private(void* addr1, int nwak
 
 }  // namespace bthread
 
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
 
 namespace bthread {
 
