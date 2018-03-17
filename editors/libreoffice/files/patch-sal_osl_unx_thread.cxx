--- sal/osl/unx/thread.cxx.orig	2017-12-12 17:31:34.756103000 +0300
+++ sal/osl/unx/thread.cxx	2017-12-12 17:33:13.924729000 +0300
@@ -45,6 +45,10 @@
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
