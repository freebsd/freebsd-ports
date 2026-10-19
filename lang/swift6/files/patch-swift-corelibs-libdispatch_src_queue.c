--- swift-corelibs-libdispatch/src/queue.c.orig	2026-10-10 18:48:34 UTC
+++ swift-corelibs-libdispatch/src/queue.c
@@ -6198,14 +6198,25 @@
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
+	// continuations consume real stack frames.  Give pool worker threads a
+	// large stack so bounded async call chains do not overflow the default.
+	r = pthread_attr_setstacksize(attr, 512 * 1024 * 1024);
+	dispatch_assume_zero(r);
+#endif // defined(__powerpc64__)
 #endif // !defined(_WIN32)
+	if (cls) {
 #if HAVE_PTHREAD_WORKQUEUE_QOS
 		r = pthread_attr_set_qos_class_np(attr, cls, 0);
 		dispatch_assume_zero(r);
