--- storage/perfschema/my_thread.h.orig	2020-06-23 15:10:17 UTC
+++ storage/perfschema/my_thread.h
@@ -10,6 +10,10 @@
 #include <sys/syscall.h>
 #endif
 
+#ifdef HAVE_PTHREAD_GETTHREADID_NP
+#include <pthread_np.h>
+#endif
+
 typedef pthread_key_t thread_local_key_t;
 typedef pthread_t my_thread_handle;
 typedef pthread_attr_t my_thread_attr_t;
