--- Sources/Core/System/Unix/thread_pthread.cpp.orig	Thu Oct  9 02:43:49 2003
+++ Sources/Core/System/Unix/thread_pthread.cpp	Tue Oct 21 01:22:12 2003
@@ -158,5 +158,5 @@
 
 int CL_Thread::get_current_id()
 {
-	return pthread_self();
+	return (int)pthread_self();
 }
