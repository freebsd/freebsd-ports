--- TSRM/threads.m4.orig	2013-12-10 23:31:06.000000000 +0000
+++ TSRM/threads.m4	2013-12-13 21:50:24.898258559 +0000
@@ -79,7 +79,7 @@ int main() {
     pthread_mutexattr_t mattr;
     int data = 1;
     pthread_mutexattr_init(&mattr);
-    return pthread_create(&thd, NULL, thread_routine, &data);
+    return 0;
 } ], [
   pthreads_working=yes
   ], [
