--- include/my_thread_os_id.h.orig	2019-10-21 05:21:41 UTC
+++ include/my_thread_os_id.h
@@ -88,8 +88,12 @@ static inline my_thread_os_id_t my_thread_os_id()
   return pthread_getthreadid_np();
 #else
 #ifdef HAVE_INTEGER_PTHREAD_SELF
+#  ifdef __DragonFly__
+  return syscall(SYS_lwp_gettid);
+#  else
   /* Unknown platform, fallback. */
   return pthread_self();
+#  endif
 #else
   /* Feature not available. */
   return 0;
