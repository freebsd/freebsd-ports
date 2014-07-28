--- tcl/uutcl.c.orig	Sat Feb 19 18:56:55 2005
+++ tcl/uutcl.c	Sat Feb 19 18:57:08 2005
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
