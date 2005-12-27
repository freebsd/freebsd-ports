--- visualization/nviz/src/nvizMain.c.orig	Tue Dec 27 10:55:33 2005
+++ visualization/nviz/src/nvizMain.c	Tue Dec 27 10:55:42 2005
@@ -11,8 +11,10 @@
  * Sun shared libraries to be used for Tcl.
  */
 
+/*
 extern int matherr();
-/*int *tclDummyMathPtr = (int *) matherr;*/
+int *tclDummyMathPtr = (int *) matherr;
+*/
 
 
 extern int NVIZ_AppInit(Tcl_Interp *);
