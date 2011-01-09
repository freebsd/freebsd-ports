--- include/my_pthread.h.orig	2011-01-09 10:17:18.000000000 +0100
+++ include/my_pthread.h	2011-01-09 12:06:33.000000000 +0100
@@ -215,7 +215,10 @@
 
 #define my_pthread_once_t pthread_once_t
 #define MY_PTHREAD_ONCE_INIT PTHREAD_ONCE_INIT
-#define my_pthread_once(C,F) pthread_once(C,F)
+#define my_pthread_once(C,F) do { \
+    if (__isthreaded) pthread_once(C,F); \
+    else if ((C)->state == PTHREAD_NEEDS_INIT) { F(); (C)->state = PTHREAD_DONE_INIT; } \
+  } while(0)
 
 /* Test first for RTS or FSU threads */
 
