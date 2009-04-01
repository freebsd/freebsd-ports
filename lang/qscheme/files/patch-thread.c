--- thread.c.orig	2009-03-03 17:22:45.000000000 +0200
+++ thread.c	2009-03-03 17:26:27.000000000 +0200
@@ -123,7 +123,8 @@
 SOBJ scm_mutex_new()
 {
   SOBJ new = scm_newcell(SOBJ_T_MUTEX);
-  SCM_MUTEX(new) = scm_must_alloc(sizeof(pthread_mutex_t));
+  /*SCM_MUTEX(new) = scm_must_alloc(sizeof(pthread_mutex_t));*/
+  SCM_MUTEX_SET(new, scm_must_alloc(sizeof(pthread_mutex_t)));
   pthread_mutex_init(SCM_MUTEX(new), NULL);
   return(new);
 }
@@ -137,7 +138,8 @@
 	} else {
 	  scm_free(SCM_MUTEX(x));
 	}
-	SCM_MUTEX(x) = NULL;
+	/*SCM_MUTEX(x) = NULL;*/
+	SCM_MUTEX_SET(x, NULL);
   }
 }
 
@@ -201,7 +203,8 @@
 {
   int n = 0;
   SOBJ new = scm_newcell(SOBJ_T_SEMAPHORE);
-  SCM_SEMAPHORE(new) = scm_must_alloc(sizeof(sem_t));
+  /*SCM_SEMAPHORE_SET(new) = scm_must_alloc(sizeof(sem_t));*/
+  SCM_SEMAPHORE_SET(new, scm_must_alloc(sizeof(sem_t)));
   if (nargs >= 1 && SCM_INUMP(arg[0])) {
 	n = SCM_INUM(n);
   }
@@ -218,7 +221,8 @@
 	} else {
 	  scm_free(SCM_SEMAPHORE(x));
 	}
-	SCM_SEMAPHORE(x) = NULL;
+	/*SCM_SEMAPHORE(x) = NULL;*/
+	SCM_SEMAPHORE_SET(x, NULL);
   }
 }
 
