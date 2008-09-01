--- ngtcltk/ngappinit.cpp.orig	2004-11-17 17:43:35.000000000 +0800
+++ ngtcltk/ngappinit.cpp	2008-09-01 22:40:22.000000000 +0800
@@ -3,10 +3,12 @@
   This file is a modification of tkAppInit.c from the Tcl/Tk package
 */
 
+using namespace std;
+
 #include <mystdlib.h>
 #include "incvis.hpp"
 #include <meshing.hpp>
-
+#include <math.h>
 
 namespace netgen
 {
@@ -26,8 +28,6 @@
  * The following variable is a special hack that is needed in order for
  * Sun shared libraries to be used for Tcl.
  */
-// extern "C" int matherr();
-int *tclDummyMathPtr = (int *) matherr;
 
 
 /*
@@ -194,8 +194,9 @@
   // For adding an application, parse the file here,
   // and call the init-procedure below
   // #define DEMOAPP
+#define DEMOAPP
 #ifdef DEMOAPP  
-  Tcl_EvalFile (myinterp, "demoapp/demoapp.tcl");
+  Tcl_EvalFile (myinterp, "%%DATADIR%%/demoapp.tcl");
 #endif
 
 #ifdef ADDON
@@ -316,7 +317,7 @@
   // #undef NGSOLVE
 
 
-#ifdef NGSOLVE
+#if 0
 
   extern int NGSolve_Init (Tcl_Interp * interp);
   if (NGSolve_Init(interp) == TCL_ERROR) 
