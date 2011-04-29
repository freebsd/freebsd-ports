--- ../gcc/gthr-posix.h	2007/08/14 02:45:23	171825
+++ ../gcc/gthr-posix.h	2008/04/21 20:40:42	178388
@@ -152,9 +152,12 @@
    it is passed so we cannot pretend that the interface is active if -pthreads
    is not specified.  On Solaris 2.5.1, the interface is not exposed at all so
    we need to play the usual game with weak symbols.  On Solaris 10 and up, a
-   working interface is always exposed.  */
+   working interface is always exposed.  On FreeBSD 6 and later, libc also
+   exposes a dummy POSIX threads interface, similar to what Solaris 2.6 up
+   to 9 does.  FreeBSD >= 700014 even provides a pthread_cancel stub in libc,
+   which means the alternate __gthread_active_p below cannot be used there.  */
 
-#if defined(__sun) && defined(__svr4__)
+#if defined(__FreeBSD__) || (defined(__sun) && defined(__svr4__))
 
 static volatile int __gthread_active = -1;
 
@@ -197,7 +200,7 @@
   return __gthread_active_latest_value != 0;
 }
 
-#else /* not Solaris */
+#else /* neither FreeBSD nor Solaris */
 
 static inline int
 __gthread_active_p (void)
@@ -207,7 +210,7 @@
   return __gthread_active_ptr != 0;
 }
 
-#endif /* Solaris */
+#endif /* FreeBSD or Solaris */
 
 #else /* not SUPPORTS_WEAK */
 
