--- ngtcltk/ngappinit.cpp.orig	Tue Feb 10 10:01:01 2004
+++ ngtcltk/ngappinit.cpp	Wed May  5 19:51:54 2004
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
@@ -26,7 +28,7 @@
  * The following variable is a special hack that is needed in order for
  * Sun shared libraries to be used for Tcl.
  */
-// extern "C" int matherr();
+extern "C" int matherr();
 int *tclDummyMathPtr = (int *) matherr;
 
 
@@ -169,20 +171,22 @@
 
   // For adding an application, parse the file here,
   // and call the init-procedure below
-  // #define DEMOAPP
+#define DEMOAPP
 #ifdef DEMOAPP  
-  //  Tcl_EvalFile (myinterp, "demoapp/demoapp.tcl");
+  Tcl_EvalFile (myinterp, "%%DATADIR%%/demoapp.tcl");
 #endif
 
+// #define METIS
+
 #ifdef ADDON
   Tcl_EvalFile (myinterp, "addon/addon.tcl");
 #endif
 
   // start event-loop
   Tk_MainLoop();
-  Tcl_DeleteInterp (myinterp); 
+  Tcl_DeleteInterp (myinterp);
 
-  return 0;		
+  return 0;
 }
 
 
@@ -268,6 +272,7 @@
     // #define NGSOLVE
     // #undef NGSOLVE
 
+/*
 #ifdef NGSOLVE
     extern int NGSolve_Init (Tcl_Interp * interp);
     if (NGSolve_Init(interp) == TCL_ERROR) 
@@ -277,6 +282,7 @@
 	return TCL_ERROR;
       }
 #endif
+*/
 
     Tcl_StaticPackage(interp, "Tk", Tk_Init, 0);
     
