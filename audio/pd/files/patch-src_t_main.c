--- src/t_main.c.orig	Sun Feb 13 00:32:01 2005
+++ src/t_main.c	Sun Feb 13 00:32:11 2005
@@ -19,14 +19,6 @@
 #include <stdlib.h>
 
 /*
- * The following variable is a special hack that is needed in order for
- * Sun shared libraries to be used for Tcl.
- */
-
-extern int matherr(void);
-int *tclDummyMathPtr = (int *) matherr;
-
-/*
  *----------------------------------------------------------------------
  *
  * main --
