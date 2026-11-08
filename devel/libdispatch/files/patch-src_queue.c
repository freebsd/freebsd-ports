--- src/queue.c.orig	2026-05-01 02:25:26 UTC
+++ src/queue.c
@@ -7552,6 +7552,24 @@ libdispatch_tsd_init(void)
 	FlsSetValue(__dispatch_tsd_key, &__dispatch_tsd);
 #endif // defined(_WIN32)
 	__dispatch_tsd.tid = _gettid();
+#if defined(__FreeBSD__)
+	/*
+	 * shims/lock.h stores the tid shifted left by two as the lock
+	 * owner, so it must fit in 30 bits.  lwpid_t is bounded by
+	 * kern.maxthread + NO_PID (about 1.1 million by default) but the
+	 * kernel does not clamp the tunable.  This runs once per thread,
+	 * on its first use of libdispatch; the failure it prevents would
+	 * otherwise be a silent owner aliasing.  Write the message with
+	 * write(2): the crash-log message macros are no-ops here.
+	 */
+	if (unlikely((dispatch_tid)__dispatch_tsd.tid > DLOCK_TID_MAX)) {
+		static const char msg[] = "BUG IN LIBDISPATCH: thread ID does "
+			"not fit the 30-bit lock owner encoding (kern.maxthread "
+			"too large)\n";
+		(void)write(STDERR_FILENO, msg, sizeof(msg) - 1);
+		_dispatch_hardware_crash();
+	}
+#endif
 }
 #endif
 
