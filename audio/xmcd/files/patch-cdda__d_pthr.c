--- cdda_d/pthr.c.orig	2004-04-21 19:27:03 UTC
+++ cdda_d/pthr.c
@@ -35,6 +35,7 @@ static char *_pthr_c_ident_ = "@(#)pthr.
 
 #ifdef CDDA_PTHREADS
 
+#include <sys/param.h>
 #include "cdda_d/pthr.h"
 
 /*
@@ -889,6 +890,7 @@ cdda_pthr_play(di_dev_t *devp, curstat_t
 	pthr_sem[DATA].v = 0;
 
 #ifndef __VMS	/* VMS has no real fork, so this does not apply */
+#if __FreeBSD_version >= 502100
 	/* Register fork handler */
 	if ((ret = pthread_atfork(NULL, NULL, cdda_pthr_atfork)) != 0) {
 		(void) sprintf(errbuf,
@@ -900,6 +902,7 @@ cdda_pthr_play(di_dev_t *devp, curstat_t
 		return FALSE;
 	}
 #endif
+#endif
 
 	/* Ignore SIGPIPE */
 	opipe = util_signal(SIGPIPE, SIG_IGN);
