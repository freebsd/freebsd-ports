--- doio.c.orig	2020-12-18 10:04:36 UTC
+++ doio.c
@@ -373,7 +373,7 @@ S_openn_setup(pTHX_ GV *gv, char *mode, PerlIO **savei
     *savefd = -1;
     *savetype = IoTYPE_CLOSED;
 
-    Zero(mode,sizeof(mode),char);
+    Zero(mode, PERL_MODE_MAX, char);
     PL_forkprocess = 1;		/* assume true if no fork */
 
     /* If currently open - close before we re-open */
