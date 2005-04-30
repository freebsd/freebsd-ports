--- ngtcltk/ngappinit.cpp.orig	Wed Nov 17 10:43:35 2004
+++ ngtcltk/ngappinit.cpp	Wed Nov 17 21:57:41 2004
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
@@ -26,7 +28,5 @@
  * The following variable is a special hack that is needed in order for
  * Sun shared libraries to be used for Tcl.
  */
-// extern "C" int matherr();
-int *tclDummyMathPtr = (int *) matherr;
 
 
@@ -194,8 +196,9 @@
   // For adding an application, parse the file here,
   // and call the init-procedure below
   // #define DEMOAPP
+#define DEMOAPP
 #ifdef DEMOAPP  
-  Tcl_EvalFile (myinterp, "demoapp/demoapp.tcl");
+  Tcl_EvalFile (myinterp, "%%DATADIR%%/demoapp.tcl");
 #endif
 
 #ifdef ADDON
