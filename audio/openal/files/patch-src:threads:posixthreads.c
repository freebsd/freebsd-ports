--- src/threads/posixthreads.c~	Mon Aug 28 19:14:08 2000
+++ src/threads/posixthreads.c	Mon Sep 25 19:17:19 2000
@@ -82,7 +82,7 @@
 }
 
 extern unsigned int Posix_SelfThread(void) {
-	return (unsigned int) pthread_self();
+	return (unsigned long)(unsigned long *) pthread_self();
 }
 
 extern void Posix_ExitThread(UNUSED(int retval)) {
