--- s.h.orig	Sun Feb 10 12:45:20 2002
+++ s.h	Sun Feb 10 12:45:32 2002
@@ -203,7 +203,7 @@
 
 #ifdef SCM_WITH_THREADS
 /*** same as in Boehm's GC */
-#define SCM_SIG_SUSPEND		SIGPWR
+#define SCM_SIG_SUSPEND		SIGUSR1
 #define SCM_SIG_RESUME		SIGXCPU
 #endif
