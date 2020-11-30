--- server/fsync.c.orig
+++ server/fsync.c
@@ -58,12 +58,16 @@
 };
 #include "poppack.h"
 
+#ifdef __linux__
+
 static inline int futex_wait_multiple( const struct futex_wait_block *futexes,
         int count, const struct timespec *timeout )
 {
     return syscall( __NR_futex, futexes, 31, count, timeout, 0, 0 );
 }
 
+#endif
+
 int do_fsync(void)
 {
 #ifdef __linux__
@@ -320,7 +324,11 @@
 
 static inline int futex_wake( int *addr, int val )
 {
+#ifdef __linux__
     return syscall( __NR_futex, addr, 1, val, NULL, 0, 0 );
+#else
+    assert(0);
+#endif
 }
 
 /* shm layout for events or event-like objects. */
