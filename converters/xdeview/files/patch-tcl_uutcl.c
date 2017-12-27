--- tcl/uutcl.c.orig	2002-03-06 13:52:45 UTC
+++ tcl/uutcl.c
@@ -48,14 +48,6 @@
 #include <tcl.h>
 #endif
 
-/*
- * The following variable is a special hack that is needed in order for
- * Sun shared libraries to be used for Tcl.
- */
-
-extern int matherr();
-int *tclDummyMathPtr = (int *) matherr;
-
 #include <uudeview.h>
 #include <uuint.h>
 #include <fptools.h>
