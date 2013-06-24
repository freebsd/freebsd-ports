--- TSRM/threads.m4.orig	2005-04-27 15:22:18.000000000 +0200
+++ TSRM/threads.m4	2009-09-22 10:01:37.000000000 +0200
@@ -79,7 +79,7 @@
     pthread_mutexattr_t mattr;
     int data = 1;
     pthread_mutexattr_init(&mattr);
-    return pthread_create(&thd, NULL, thread_routine, &data);
+    return 0;
 } ], [
   pthreads_working=yes
   ], [
