--- src/shims/lock.c.orig	2026-05-01 02:25:26 UTC
+++ src/shims/lock.c
@@ -447,11 +447,15 @@ _futex_blocking_op(uint32_t *uaddr, int futex_op, uint
 		const struct timespec *timeout, int flags)
 {
 	for (;;) {
-		int rc = _dispatch_futex(uaddr, futex_op, val, timeout, NULL, 0, flags);
-		if (!rc) {
+		int err = _dispatch_futex(uaddr, futex_op, val, timeout, NULL, 0, flags);
+		if (!err) {
 			return 0;
 		}
-		switch (errno) {
+#if __linux__
+		// syscall sets errno to communicate error code.
+		err = errno
+#endif
+		switch (err) {
 		case EINTR:
 			/*
 			 * if we have a timeout, we need to return for the caller to
@@ -478,6 +482,7 @@ _dispatch_futex_wait(uint32_t *uaddr, uint32_t val,
 	return _futex_blocking_op(uaddr, FUTEX_WAIT, val, timeout, opflags);
 }
 
+#if HAVE_FUTEX_PI
 static void
 _dispatch_futex_wake(uint32_t *uaddr, int wake, int opflags)
 {
@@ -486,6 +491,7 @@ _dispatch_futex_wake(uint32_t *uaddr, int wake, int op
 	if (rc >= 0 || errno == ENOENT) return;
 	DISPATCH_INTERNAL_CRASH(errno, "_dlock_wake() failed");
 }
+#endif
 
 #if HAVE_FUTEX_PI
 static void
