--- src/shims/lock.h.orig	2025-03-07 00:50:44 UTC
+++ src/shims/lock.h
@@ -100,6 +100,29 @@ _dispatch_lock_owner(dispatch_lock lock_value)
 	return lock_value & DLOCK_OWNER_MASK;
 }
 
+#elif defined(__FreeBSD__)
+
+#include <sys/types.h>
+#include <sys/umtx.h>
+#include <sched.h>
+
+typedef uint32_t dispatch_tid;
+typedef uint32_t dispatch_lock;
+
+#define DLOCK_OWNER_NULL   ((dispatch_tid)0)
+#define DLOCK_OWNER_MASK   ((dispatch_lock)0xfffffffc)
+#define DLOCK_WAITERS_BIT   ((dispatch_lock)0x00000001)
+#define DLOCK_FAILED_TRYLOCK_BIT  ((dispatch_lock)0x00000002)
+
+#define _dispatch_tid_self()        ((dispatch_tid)(_dispatch_get_tsd_base()->tid))
+
+DISPATCH_ALWAYS_INLINE
+static inline dispatch_tid
+_dispatch_lock_owner(dispatch_lock lock_value)
+{
+  return lock_value & DLOCK_OWNER_MASK;
+}
+
 #else
 #  error define _dispatch_lock encoding scheme for your platform here
 #endif
@@ -167,10 +190,15 @@ _dispatch_lock_has_failed_trylock(dispatch_lock lock_v
 #endif
 
 #ifndef HAVE_FUTEX
-#ifdef __linux__
+#if defined(__linux__)
 #define HAVE_FUTEX 1
+#define HAVE_FUTEX_PI 1
+#elif defined(__FreeBSD__)
+#define HAVE_FUTEX 0
+#define HAVE_FUTEX_PI 0
 #else
 #define HAVE_FUTEX 0
+#define HAVE_FUTEX_PI 0
 #endif
 #endif // HAVE_FUTEX
 
