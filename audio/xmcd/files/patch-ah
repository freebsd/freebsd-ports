--- cdda_d/pthr.c.orig	Mon Apr  5 17:41:11 2004
+++ cdda_d/pthr.c	Sun Apr 11 01:15:11 2004
@@ -35,6 +35,7 @@
 
 #ifdef CDDA_PTHREADS
 
+#include <sys/param.h>
 #include "cdda_d/pthr.h"
 
 /*
@@ -889,6 +890,7 @@
 	pthr_sem[DATA].v = 0;
 
 #ifndef __VMS	/* VMS has no real fork, so this does not apply */
+#if __FreeBSD_version >= 502100
 	/* Register fork handler */
 	if ((ret = pthread_atfork(NULL, NULL, cdda_pthr_atfork)) != 0) {
 		(void) sprintf(errbuf,
@@ -899,6 +901,7 @@
 		cd->i->state = CDSTAT_COMPLETED;
 		return FALSE;
 	}
+#endif
 #endif
 
 	/* Ignore SIGPIPE */
