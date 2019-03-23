osl_thread_priority_init_Impl() tries to assign values to variables
declared as const on platforms not excluded by NO_PTHREAD_PRIORITY.
This includes FreeBSD.  Patch locally until fixed upstream.

--- sal/osl/unx/thread.cxx.orig	2019-02-12 22:11:36.000000000 +0000
+++ sal/osl/unx/thread.cxx	2019-02-18 23:03:57.933036000 +0000
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
@@ -88,11 +92,11 @@
 
 struct osl_thread_priority_st
 {
-    int const m_Highest;
-    int const m_Above_Normal;
-    int const m_Normal;
-    int const m_Below_Normal;
-    int const m_Lowest;
+    int m_Highest;
+    int m_Above_Normal;
+    int m_Normal;
+    int m_Below_Normal;
+    int m_Lowest;
 };
 
 #define OSL_THREAD_PRIORITY_INITIALIZER { 127, 96, 64, 32, 0 }
@@ -110,7 +114,7 @@
 struct osl_thread_global_st
 {
     pthread_once_t                    m_once;
-    struct osl_thread_priority_st const m_priority;
+    struct osl_thread_priority_st     m_priority;
     struct osl_thread_textencoding_st m_textencoding;
 };
 
@@ -545,7 +549,7 @@
     if ( 0 != err )
         SAL_WARN("sal.osl", "pthread_setname_np failed with errno " << err);
 #elif defined __FreeBSD_kernel__
-    pthread_setname_np( pthread_self(), name );
+    pthread_set_name_np( pthread_self(), name );
 #elif defined MACOSX || defined IOS
     pthread_setname_np( name );
 #else
