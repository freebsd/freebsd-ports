--- visualization/nviz/src/nvizAppInit.c.orig	Tue Dec 27 10:55:14 2005
+++ visualization/nviz/src/nvizAppInit.c	Tue Dec 27 10:55:25 2005
@@ -22,8 +22,10 @@
  * Sun shared libraries to be used for Tcl.
 */
 
+/*
 extern int matherr();
 int *tclDummyMathPtr = (int *) matherr;
+*/
 
 /*
  *----------------------------------------------------------------------
