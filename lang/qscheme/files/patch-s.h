--- s.h.orig	2000-06-16 00:15:42.000000000 +0300
+++ s.h	2009-03-03 17:35:11.000000000 +0200
@@ -203,7 +203,7 @@
 
 #ifdef SCM_WITH_THREADS
 /*** same as in Boehm's GC */
-#define SCM_SIG_SUSPEND		SIGPWR
+#define SCM_SIG_SUSPEND		SIGUSR1
 #define SCM_SIG_RESUME		SIGXCPU
 #endif
 
@@ -539,6 +539,7 @@
 #define SCM_CATCH_CONTEXT_UNWIND(x)		SCM_CATCH_CONTEXT(x)->unwind
 
 #define SCM_AUX(x)					SCM_VALUE(x,aux,aux)
+#define SCM_AUX_SET(x,v)				SCM_VALUE(x,aux,aux)=(v);
 
 /*-- type predicates */
 /*#define SCM_OBJTYPE(x)	(SCM_INUMP(x)?SOBJ_T_INUM:(x?SCM_OBJREF(x)->type:-1)) */
@@ -656,6 +657,11 @@
   SCM_ERR_THROW,
   SCM_ERR_MAX };
 
+struct CHR_SYM {
+  char *str;
+  char chr;
+};
+
 #include "sproto.h"
 
 #define scm_sp			scm_vmd()->reg.sp
@@ -668,6 +674,8 @@
 #define SCM_THREAD(x)		((SCM_VMD*)(SCM_AUX(x)))
 #define SCM_MUTEX(x)		((pthread_mutex_t *)SCM_AUX(x))
 #define SCM_SEMAPHORE(x)	((sem_t *)SCM_AUX(x))
+#define SCM_MUTEX_SET		SCM_AUX_SET
+#define SCM_SEMAPHORE_SET	SCM_AUX_SET
 
 #define SCM_THREADP(x)		(SCM_OBJTYPE(x) == SOBJ_T_THREAD)
 #define SCM_MUTEXP(x)		(SCM_OBJTYPE(x) == SOBJ_T_MUTEX)
