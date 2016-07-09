--- threadutil/inc/ithread.h.orig	2013-11-14 17:14:44 UTC
+++ threadutil/inc/ithread.h
@@ -50,12 +50,9 @@ extern "C" {
 
 #include <pthread.h>
 
-#if defined(BSD) && !defined(__GNU__)
-	#define PTHREAD_MUTEX_RECURSIVE_NP PTHREAD_MUTEX_RECURSIVE
-#endif
 
 
-#if defined(PTHREAD_MUTEX_RECURSIVE) || defined(__DragonFly__)
+#if defined(PTHREAD_MUTEX_RECURSIVE) || defined(__DragonFly__) || defined(__FreeBSD__)
 	/* This system has SuS2-compliant mutex attributes.
 	 * E.g. on Cygwin, where we don't have the old nonportable (NP) symbols
 	 */
