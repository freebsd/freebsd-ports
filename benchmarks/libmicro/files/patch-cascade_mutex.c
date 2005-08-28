--- cascade_mutex.c.orig	Sat Aug  6 14:10:03 2005
+++ cascade_mutex.c	Sat Aug  6 14:11:53 2005
@@ -83,7 +83,6 @@
 	lm_defN = "cscd_mutex";
 
 	(void) sprintf(lm_usage,
-	    "       [-s] (force PTHREAD_PROCESS_SHARED)\n"
 	    "notes: thread cascade using pthread_mutexes\n");
 
 	return (0);
@@ -94,9 +93,6 @@
 benchmark_optswitch(int opt, char *optarg)
 {
 	switch (opt) {
-	case 's':
-		opts = 1;
-		break;
 	default:
 		return (-1);
 	}
@@ -123,6 +119,7 @@
 	}
 
 	(void) pthread_mutexattr_init(&ma);
+#if !defined(__FreeBSD__)
 	if (lm_optP > 1 || opts) {
 		(void) pthread_mutexattr_setpshared(&ma,
 		    PTHREAD_PROCESS_SHARED);
@@ -130,6 +127,7 @@
 		(void) pthread_mutexattr_setpshared(&ma,
 		    PTHREAD_PROCESS_PRIVATE);
 	}
+#endif
 
 	for (i = 0; i < nlocks; i++) {
 		(void) pthread_mutex_init(&locks[i], &ma);
