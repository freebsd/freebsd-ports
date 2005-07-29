--- rsc/source/rscpp/cpp3.c.orig	Thu Jul 25 00:00:25 2002
+++ rsc/source/rscpp/cpp3.c	Thu Jul 25 00:01:50 2002
@@ -82,7 +82,9 @@
 #ifdef IRIX
 extern void 	abort(void);
 #else
+#ifndef FREEBSD
 extern int      abort();                /* For debugging                */
+#endif
 #endif
 #endif
 
