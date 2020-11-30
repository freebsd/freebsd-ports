--- dlls/ntdll/unix/fsync.c.orig
+++ dlls/ntdll/unix/fsync.c
@@ -76,17 +76,29 @@
 static inline int futex_wait_multiple( const struct futex_wait_block *futexes,
         int count, const struct timespec *timeout )
 {
+#ifdef __linux__
     return syscall( __NR_futex, futexes, 31, count, timeout, 0, 0 );
+#else
+    assert(0);
+#endif
 }
 
 static inline int futex_wake( int *addr, int val )
 {
+#ifdef __linux__
     return syscall( __NR_futex, addr, 1, val, NULL, 0, 0 );
+#else
+    assert(0);
+#endif
 }
 
 static inline int futex_wait( int *addr, int val, struct timespec *timeout )
 {
+#ifdef __linux__
     return syscall( __NR_futex, addr, 0, val, timeout, 0, 0 );
+#else
+    assert(0);
+#endif
 }
 
 static unsigned int spincount;
