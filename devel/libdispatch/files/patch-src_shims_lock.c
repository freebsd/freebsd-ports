--- src/shims/lock.c.orig	2023-06-15 00:55:45 UTC
+++ src/shims/lock.c
@@ -56,6 +56,18 @@ _dispatch_thread_switch(dispatch_lock value, dispatch_
 #endif
 #endif
 
+#if defined(__unix__)
+DISPATCH_ALWAYS_INLINE
+static inline void
+_dispatch_thread_switch(dispatch_lock value, dispatch_lock_options_t flags,
+  uint32_t timeout)
+{
+	(void)value;
+	(void)flags;
+	(void)timeout;
+}
+#endif
+
 #pragma mark - semaphores
 
 #if USE_MACH_SEM
@@ -395,8 +407,10 @@ _dispatch_unfair_lock_wake(uint32_t *uaddr, uint32_t f
 #include <sys/time.h>
 #ifdef __ANDROID__
 #include <sys/syscall.h>
-#else
+#elif __linux__
 #include <syscall.h>
+#else
+#include <sys/futex.h>
 #endif /* __ANDROID__ */
 
 DISPATCH_ALWAYS_INLINE
@@ -405,7 +419,12 @@ _dispatch_futex(uint32_t *uaddr, int op, uint32_t val,
 		const struct timespec *timeout, uint32_t *uaddr2, uint32_t val3,
 		int opflags)
 {
+#if __linux__
 	return (int)syscall(SYS_futex, uaddr, op | opflags, val, timeout, uaddr2, val3);
+#else
+	(void)val3;
+	return futex(uaddr, op | opflags, (int)val, timeout, uaddr2);
+#endif
 }
 
 // returns 0, ETIMEDOUT, EFAULT, EINTR, EWOULDBLOCK
@@ -415,11 +434,15 @@ _futex_blocking_op(uint32_t *uaddr, int futex_op, uint
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
@@ -455,6 +478,7 @@ _dispatch_futex_wake(uint32_t *uaddr, int wake, int op
 	DISPATCH_INTERNAL_CRASH(errno, "_dlock_wake() failed");
 }
 
+#if HAVE_FUTEX_PI
 static void
 _dispatch_futex_lock_pi(uint32_t *uaddr, struct timespec *timeout, int detect,
 	      int opflags)
@@ -472,6 +496,7 @@ _dispatch_futex_unlock_pi(uint32_t *uaddr, int opflags
 	if (rc == 0) return;
 	DISPATCH_CLIENT_CRASH(errno, "futex_unlock_pi() failed");
 }
+#endif
 
 #endif
 #pragma mark - wait for address
@@ -516,6 +541,19 @@ _dispatch_wait_on_address(uint32_t volatile *_address,
 			? INFINITE : ((nsecs + 1000000) / 1000000);
 	if (dwMilliseconds == 0) return ETIMEDOUT;
 	return WaitOnAddress(address, &value, sizeof(value), dwMilliseconds) == TRUE;
+#elif defined(__FreeBSD__)
+	uint64_t usecs = 0;
+	int rc;
+	if (nsecs == DISPATCH_TIME_FOREVER) {
+		return _dispatch_ulock_wait(address, value, 0, flags);
+	}
+	do {
+		usecs = howmany(nsecs, NSEC_PER_USEC);
+		if (usecs > UINT32_MAX) usecs = UINT32_MAX;
+		rc = _dispatch_ulock_wait(address, value, (uint32_t)usecs, flags);
+	} while (usecs == UINT32_MAX && rc == ETIMEDOUT &&
+			(nsecs = _dispatch_timeout(timeout)) != 0);
+	return rc;
 #else
 #error _dispatch_wait_on_address unimplemented for this platform
 #endif
@@ -606,7 +644,7 @@ _dispatch_unfair_lock_lock_slow(dispatch_unfair_lock_t
 		}
 	}
 }
-#elif HAVE_FUTEX
+#elif HAVE_FUTEX_PI
 void
 _dispatch_unfair_lock_lock_slow(dispatch_unfair_lock_t dul,
 		dispatch_lock_options_t flags)
@@ -643,7 +681,7 @@ _dispatch_unfair_lock_unlock_slow(dispatch_unfair_lock
 	if (_dispatch_lock_has_waiters(cur)) {
 		_dispatch_unfair_lock_wake(&dul->dul_lock, 0);
 	}
-#elif HAVE_FUTEX
+#elif HAVE_FUTEX_PI
 	// futex_unlock_pi() handles both OWNER_DIED which we abuse & WAITERS
 	_dispatch_futex_unlock_pi(&dul->dul_lock, FUTEX_PRIVATE_FLAG);
 #else
