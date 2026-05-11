--- src/ks_thread.c.orig	2026-05-09 17:13:52 UTC
+++ src/ks_thread.c
@@ -76,6 +76,8 @@ KS_DECLARE(ks_pid_t) ks_thread_self_id(void)
 	return GetCurrentThreadId();
 #elif defined(KS_PLAT_LIN)
 	return syscall(SYS_gettid);
+#elif defined(KS_PLAT_FBSD)
+	return pthread_getthreadid_np();
 #elif defined(KS_PLAT_MAC)
 	uint64_t tid;
 	int r = pthread_threadid_np(NULL, &tid);
