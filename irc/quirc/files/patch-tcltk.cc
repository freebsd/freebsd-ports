--- tcltk.cc.orig	2004-01-12 10:25:11.000000000 +0100
+++ tcltk.cc	2013-05-14 10:57:51.000000000 +0200
@@ -1,6 +1,7 @@
 #include <stdlib.h>
 #include <stdarg.h>
 #include <string.h>
+#include <sys/types.h>
 
 #ifdef DMALLOC
 #include <dmalloc.h>
@@ -33,7 +34,7 @@
 #endif
 
   if (Tcl_Init(TT_Interp) == TCL_ERROR) { 
-    fprintf(stderr,"Error initializing Tcl:\n%s\n",TT_Interp->result);
+    fprintf(stderr,"Error initializing Tcl:\n%s\n",Tcl_GetStringResult(TT_Interp));
     return TCL_ERROR;
   }
 
@@ -43,7 +44,7 @@
   // uses Tk_Init to process its command-line arguments).
 
   if (Tk_Init(TT_Interp) == TCL_ERROR) {
-    fprintf(stderr,"Error initializing Tk:\n%s\n",TT_Interp->result);
+    fprintf(stderr,"Error initializing Tk:\n%s\n",Tcl_GetStringResult(TT_Interp));
     return TCL_ERROR;
   }
 
