--- swift-corelibs-libdispatch/src/queue.c.orig	2026-05-01 02:25:26 UTC
+++ swift-corelibs-libdispatch/src/queue.c
@@ -6198,14 +6198,26 @@ _dispatch_root_queue_init_pthread_pool(dispatch_queue_
 	dq->dgq_thread_pool_size = thread_pool_size;
 	qos_class_t cls = _dispatch_qos_to_qos_class(_dispatch_priority_qos(pri) ?:
 			_dispatch_priority_fallback_qos(pri));
-	if (cls) {
 #if !defined(_WIN32)
-		pthread_attr_t *attr = &pqc->dpq_thread_attr;
-		int r = pthread_attr_init(attr);
-		dispatch_assume_zero(r);
-		r = pthread_attr_setdetachstate(attr, PTHREAD_CREATE_DETACHED);
-		dispatch_assume_zero(r);
+	// Always initialize the worker thread attributes: platforms without QoS
+	// classes (such as FreeBSD) never enter the cls branch, but targets that
+	// need a larger worker stack (see below) still require the attributes.
+	pthread_attr_t *attr = &pqc->dpq_thread_attr;
+	int r = pthread_attr_init(attr);
+	dispatch_assume_zero(r);
+	r = pthread_attr_setdetachstate(attr, PTHREAD_CREATE_DETACHED);
+	dispatch_assume_zero(r);
+#if defined(__powerpc64__)
+	// LLVM cannot emit guaranteed tail calls for the indirect continuation
+	// calls Swift concurrency relies on (swifttailcc) on PowerPC, so async
+	// continuations consume real stack frames.  Bootstrapping SwiftPM grows a
+	// worker stack to about 13 MiB on FreeBSD/powerpc64le; the 2 MiB default
+	// and 8 MiB both overflow.  The reservation is address space only.
+	r = pthread_attr_setstacksize(attr, 32 * 1024 * 1024);
+	dispatch_assume_zero(r);
+#endif // defined(__powerpc64__)
 #endif // !defined(_WIN32)
+	if (cls) {
 #if HAVE_PTHREAD_WORKQUEUE_QOS
 		r = pthread_attr_set_qos_class_np(attr, cls, 0);
 		dispatch_assume_zero(r);
@@ -7552,6 +7564,24 @@ libdispatch_tsd_init(void)
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
 
