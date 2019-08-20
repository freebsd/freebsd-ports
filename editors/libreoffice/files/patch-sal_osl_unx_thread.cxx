osl_thread_priority_init_Impl() tries to assign values to variables
declared as const on platforms not excluded by NO_PTHREAD_PRIORITY.
This includes FreeBSD.  This is https://gerrit.libreoffice.org/69603
upstream, and this comment and the relevant parts of this patch can
be removed if/when that is merged.

--- sal/osl/unx/thread.cxx.orig	2019-08-08 19:56:46.260832000 +0800
+++ sal/osl/unx/thread.cxx	2019-08-08 19:56:45.711297000 +0800
@@ -46,6 +46,10 @@
 #include <sys/syscall.h>
 #endif
 
+#ifdef __FreeBSD_kernel__
+#include <pthread_np.h>
+#endif
+
 /****************************************************************************
  * @@@ TODO @@@
  *
@@ -545,7 +549,7 @@
     if ( 0 != err )
         SAL_WARN("sal.osl", "pthread_setname_np failed with errno " << err);
 #elif defined __FreeBSD_kernel__
-    pthread_setname_np( pthread_self(), name );
+    pthread_set_name_np( pthread_self(), name );
 #elif defined MACOSX || defined IOS
     pthread_setname_np( name );
 #else
