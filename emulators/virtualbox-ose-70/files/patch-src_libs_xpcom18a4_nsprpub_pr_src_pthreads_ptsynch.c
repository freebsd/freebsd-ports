--- src/libs/xpcom18a4/nsprpub/pr/src/pthreads/ptsynch.c.orig	2019-04-16 10:18:41 UTC
+++ src/libs/xpcom18a4/nsprpub/pr/src/pthreads/ptsynch.c
@@ -49,6 +49,9 @@
 #include <string.h>
 #include <pthread.h>
 #include <sys/time.h>
+#ifdef FREEBSD
+#include <sys/param.h>
+#endif
 
 static pthread_mutexattr_t _pt_mattr;
 static pthread_condattr_t _pt_cvar_attr;
@@ -798,6 +801,7 @@ PR_IMPLEMENT(PRStatus) PR_DeleteSemaphore(const char *
  * From the semctl(2) man page in glibc 2.0
  */
 #if (defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)) \
+    || (defined(FREEBSD) && __FreeBSD_version < 1200059) \
     || defined(OPENBSD) || defined(BSDI)
 /* union semun is defined by including <sys/sem.h> */
 #else
