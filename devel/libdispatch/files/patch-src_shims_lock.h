--- src/shims/lock.h.orig	2026-05-01 02:25:26 UTC
+++ src/shims/lock.h
@@ -92,7 +92,15 @@ typedef uint32_t dispatch_lock;
 #define DLOCK_OWNER_MASK			((dispatch_lock)0xfffffffc)
 #define DLOCK_WAITERS_BIT			((dispatch_lock)0x00000001)
 #define DLOCK_FAILED_TRYLOCK_BIT		((dispatch_lock)0x00000002)
-#define _dispatch_tid_self()			((dispatch_tid)(_dispatch_get_tsd_base()->tid << 2))
+/*
+ * The kernel tid (a signed lwpid_t) is shifted clear of the two flag bits.
+ * Convert to the unsigned lock type BEFORE shifting: a left shift of a
+ * signed int is undefined once the result no longer fits, and nothing here
+ * may depend on the tid's magnitude.  libdispatch_tsd_init() rejects tids
+ * above DLOCK_TID_MAX, so the shift never discards bits in practice.
+ */
+#define DLOCK_TID_MAX				((dispatch_tid)(DLOCK_OWNER_MASK >> 2))
+#define _dispatch_tid_self()			(((dispatch_tid)_dispatch_get_tsd_base()->tid) << 2)
 
 DISPATCH_ALWAYS_INLINE
 static inline dispatch_tid
@@ -213,6 +221,9 @@ _dispatch_lock_has_failed_trylock(dispatch_lock lock_v
 #define HAVE_FUTEX_PI 1
 #elif defined(__OpenBSD__)
 #define HAVE_FUTEX 1
+#define HAVE_FUTEX_PI 0
+#elif defined(__FreeBSD__)
+#define HAVE_FUTEX 0
 #define HAVE_FUTEX_PI 0
 #else
 #define HAVE_FUTEX 0
