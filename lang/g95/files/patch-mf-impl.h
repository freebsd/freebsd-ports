--- libmudflap/mf-impl.h.org	Sat Jan 31 20:35:05 2004
+++ libmudflap/mf-impl.h	Sat Jan 31 20:35:20 2004
@@ -17,11 +17,11 @@
 #error "Do not compile this file with -fmudflap!"
 #endif
 
-#if HAVE_PTHREAD_H
+//#if HAVE_PTHREAD_H
 #include <pthread.h>
-#elif LIBMUDFLAPTH
-#error "Cannot build libmudflapth without pthread.h."
-#endif
+//#elif LIBMUDFLAPTH
+//#error "Cannot build libmudflapth without pthread.h."
+//#endif
 
 
 /* Private definitions related to mf-runtime.h  */
