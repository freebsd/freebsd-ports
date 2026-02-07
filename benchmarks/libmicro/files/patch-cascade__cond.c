--- cascade_cond.c.orig	2011-05-11 00:58:23 UTC
+++ cascade_cond.c
@@ -83,7 +83,6 @@ benchmark_init()
 
 	(void) sprintf(lm_usage,
 	    "       [-o] (do signal outside mutex)\n"
-	    "       [-s] (force PTHREAD_PROCESS_SHARED)\n"
 	    "notes: thread cascade using pthread_conds\n");
 
 	return (0);
@@ -97,9 +96,6 @@ benchmark_optswitch(int opt, char *optar
 	case 'o':
 		opto = 1;
 		break;
-	case 's':
-		opts = 1;
-		break;
 	default:
 		return (-1);
 	}
@@ -148,6 +144,7 @@ benchmark_initrun()
 
 	(void) pthread_mutexattr_init(&ma);
 	(void) pthread_condattr_init(&ca);
+#if !defined(__FreeBSD__)
 	if (lm_optP > 1 || opts) {
 		(void) pthread_mutexattr_setpshared(&ma,
 		    PTHREAD_PROCESS_SHARED);
@@ -159,6 +156,7 @@ benchmark_initrun()
 		(void) pthread_condattr_setpshared(&ca,
 		    PTHREAD_PROCESS_PRIVATE);
 	}
+#endif
 
 	for (i = 0; i < nlocks; i++) {
 		(void) pthread_mutex_init(&mxs[i], &ma);
