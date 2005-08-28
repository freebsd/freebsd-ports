--- cascade_cond.c.orig	Sat Aug  6 14:12:15 2005
+++ cascade_cond.c	Sat Aug  6 14:13:17 2005
@@ -87,7 +87,6 @@
 
 	(void) sprintf(lm_usage,
 	    "       [-o] (do signal outside mutex)\n"
-	    "       [-s] (force PTHREAD_PROCESS_SHARED)\n"
 	    "notes: thread cascade using pthread_conds\n");
 
 	return (0);
@@ -101,9 +100,6 @@
 	case 'o':
 		opto = 1;
 		break;
-	case 's':
-		opts = 1;
-		break;
 	default:
 		return (-1);
 	}
@@ -152,6 +148,7 @@
 
 	(void) pthread_mutexattr_init(&ma);
 	(void) pthread_condattr_init(&ca);
+#if !defined(__FreeBSD__)
 	if (lm_optP > 1 || opts) {
 		(void) pthread_mutexattr_setpshared(&ma,
 		    PTHREAD_PROCESS_SHARED);
@@ -163,6 +160,7 @@
 		(void) pthread_condattr_setpshared(&ca,
 		    PTHREAD_PROCESS_PRIVATE);
 	}
+#endif
 
 	for (i = 0; i < nlocks; i++) {
 		(void) pthread_mutex_init(&mxs[i], &ma);
