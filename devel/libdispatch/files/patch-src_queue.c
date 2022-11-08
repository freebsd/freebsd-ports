--- src/queue.c.orig	2021-09-17 04:54:52 UTC
+++ src/queue.c
@@ -6469,6 +6469,8 @@ _dispatch_runloop_handle_is_valid(dispatch_runloop_han
 	return MACH_PORT_VALID(handle);
 #elif defined(__linux__)
 	return handle >= 0;
+#elif defined(__unix__)
+	return handle >= 0;
 #elif defined(_WIN32)
 	return handle != NULL;
 #else
@@ -6485,6 +6487,8 @@ _dispatch_runloop_queue_get_handle(dispatch_lane_t dq)
 #elif defined(__linux__)
 	// decode: 0 is a valid fd, so offset by 1 to distinguish from NULL
 	return ((dispatch_runloop_handle_t)(uintptr_t)dq->do_ctxt) - 1;
+#elif defined(__unix__)
+	return ((dispatch_runloop_handle_t)(uintptr_t)dq->do_ctxt);
 #elif defined(_WIN32)
 	return ((dispatch_runloop_handle_t)(uintptr_t)dq->do_ctxt);
 #else
@@ -6502,6 +6506,8 @@ _dispatch_runloop_queue_set_handle(dispatch_lane_t dq,
 #elif defined(__linux__)
 	// encode: 0 is a valid fd, so offset by 1 to distinguish from NULL
 	dq->do_ctxt = (void *)(uintptr_t)(handle + 1);
+#elif defined(__unix__)
+	dq->do_ctxt = (void *)(uintptr_t)handle;
 #elif defined(_WIN32)
 	dq->do_ctxt = (void *)(uintptr_t)handle;
 #else
@@ -6509,6 +6515,12 @@ _dispatch_runloop_queue_set_handle(dispatch_lane_t dq,
 #endif
 }
 
+#if defined(__unix__)
+#define DISPATCH_RUNLOOP_HANDLE_PACK(rfd, wfd) (((uint64_t)(rfd) << 32) | (wfd))
+#define DISPATCH_RUNLOOP_HANDLE_RFD(h) ((int)((h) >> 32))
+#define DISPATCH_RUNLOOP_HANDLE_WFD(h) ((int)((h) & 0xffffffff))
+#endif
+
 static void
 _dispatch_runloop_queue_handle_init(void *ctxt)
 {
@@ -6558,6 +6570,14 @@ _dispatch_runloop_queue_handle_init(void *ctxt)
 		}
 	}
 	handle = fd;
+#elif defined(__unix__)
+	int fds[2];
+	int r = pipe2(fds, O_CLOEXEC | O_NONBLOCK);
+	if (r == -1) {
+		DISPATCH_CLIENT_CRASH(errno, "pipe2 failure");
+	}
+	uint32_t rfd = (uint32_t)fds[0], wfd = (uint32_t)fds[1];
+	handle = DISPATCH_RUNLOOP_HANDLE_PACK(rfd, wfd);
 #elif defined(_WIN32)
 	HANDLE hEvent;
 	hEvent = CreateEventW(NULL, /*bManualReset=*/FALSE,
@@ -6592,6 +6612,11 @@ _dispatch_runloop_queue_handle_dispose(dispatch_lane_t
 #elif defined(__linux__)
 	int rc = close(handle);
 	(void)dispatch_assume_zero(rc);
+#elif defined(__unix__)
+	int rc = close(DISPATCH_RUNLOOP_HANDLE_WFD(handle));
+	(void)dispatch_assume_zero(rc);
+	rc = close(DISPATCH_RUNLOOP_HANDLE_RFD(handle));
+	(void)dispatch_assume_zero(rc);
 #elif defined(_WIN32)
 	BOOL bSuccess;
 	bSuccess = CloseHandle(handle);
@@ -6628,6 +6653,13 @@ _dispatch_runloop_queue_class_poke(dispatch_lane_t dq)
 		result = eventfd_write(handle, 1);
 	} while (result == -1 && errno == EINTR);
 	(void)dispatch_assume_zero(result);
+#elif defined(__unix__)
+	int wfd = DISPATCH_RUNLOOP_HANDLE_WFD(handle);
+	ssize_t result;
+	do {
+		result = write(wfd, "x", 1);
+	} while (result == -1 && errno == EINTR);
+	(void)dispatch_assume_zero(result - 1);
 #elif defined(_WIN32)
 	BOOL bSuccess;
 	bSuccess = SetEvent(handle);
@@ -6915,7 +6947,7 @@ _dispatch_runloop_root_queue_wakeup_4CF(dispatch_queue
 	_dispatch_runloop_queue_wakeup(upcast(dq)._dl, 0, false);
 }
 
-#if TARGET_OS_MAC || defined(_WIN32)
+#if TARGET_OS_MAC || defined(_WIN32) || defined(__FreeBSD__)
 dispatch_runloop_handle_t
 _dispatch_runloop_root_queue_get_port_4CF(dispatch_queue_t dq)
 {
@@ -7304,6 +7336,13 @@ _gettid(void)
 _gettid(void)
 {
 	return (pid_t)pthread_getthreadid_np();
+}
+#elif defined(__FreeBSD__)
+DISPATCH_ALWAYS_INLINE
+static inline pid_t
+_gettid(void)
+{
+	return getthrid();
 }
 #elif defined(_WIN32)
 DISPATCH_ALWAYS_INLINE
