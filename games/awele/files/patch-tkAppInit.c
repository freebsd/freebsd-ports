--- tkAppInit.c.orig	Fri Dec  8 16:35:38 1995
+++ tkAppInit.c	Thu Mar 15 08:44:13 2007
@@ -9,12 +9,10 @@
  *
  * See the file "license.terms" for information on usage and redistribution
  * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
+ *
+ * SCCS: @(#) tkAppInit.c 1.22 96/05/29 09:47:08
  */
 
-#ifndef lint
-static char sccsid[] = "@(#) tkAppInit.c 1.15 95/06/28 13:14:28";
-#endif /* not lint */
-
 #include "tk.h"
 
 extern void create_commands(Tcl_Interp *,Tk_Window);
@@ -25,9 +23,7 @@
  * Sun shared libraries to be used for Tcl.
  */
 
-extern int matherr();
-int *tclDummyMathPtr = (int *) matherr;
-
+
 /*
  *----------------------------------------------------------------------
  *
@@ -77,14 +73,13 @@
 Tcl_AppInit(interp)
     Tcl_Interp *interp;		/* Interpreter for application. */
 {
-    Tk_Window main;
-
     if (Tcl_Init(interp) == TCL_ERROR) {
 	return TCL_ERROR;
     }
     if (Tk_Init(interp) == TCL_ERROR) {
 	return TCL_ERROR;
     }
+    Tcl_StaticPackage(interp, "Tk", Tk_Init, Tk_SafeInit);
 
     /*
      * Call the init procedures for included packages.  Each call should
@@ -110,10 +105,7 @@
      * where "app" is the name of the application.  If this line is deleted
      * then no user-specific startup file will be run under any conditions.
      */
-#ifdef DEFAULT_TCL_SCRIPT
-    tcl_RcFileName = DEFAULT_TCL_SCRIPT ;
-#else
-    tcl_RcFileName = "~/.wishrc";
-#endif
+
+    Tcl_SetVar(interp, "tcl_rcFileName", "~/.wishrc", TCL_GLOBAL_ONLY);
     return TCL_OK;
 }
