--- cascade_mutex.c.orig	2011-05-11 00:58:23 UTC
+++ cascade_mutex.c
@@ -79,7 +79,6 @@ benchmark_init()
 	lm_defN = "cscd_mutex";
 
 	(void) sprintf(lm_usage,
-	    "       [-s] (force PTHREAD_PROCESS_SHARED)\n"
 	    "notes: thread cascade using pthread_mutexes\n");
 
 	return (0);
@@ -90,9 +89,6 @@ int
 benchmark_optswitch(int opt, char *optarg)
 {
 	switch (opt) {
-	case 's':
-		opts = 1;
-		break;
 	default:
 		return (-1);
 	}
@@ -119,6 +115,7 @@ benchmark_initrun()
 	}
 
 	(void) pthread_mutexattr_init(&ma);
+#if !defined(__FreeBSD__)
 	if (lm_optP > 1 || opts) {
 		(void) pthread_mutexattr_setpshared(&ma,
 		    PTHREAD_PROCESS_SHARED);
@@ -126,6 +123,7 @@ benchmark_initrun()
 		(void) pthread_mutexattr_setpshared(&ma,
 		    PTHREAD_PROCESS_PRIVATE);
 	}
+#endif
 
 	for (i = 0; i < nlocks; i++) {
 		(void) pthread_mutex_init(&locks[i], &ma);
