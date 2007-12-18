--- plugins/ayslx.c.orig	2007-09-21 13:30:37.000000000 +0200
+++ plugins/ayslx.c	2007-12-17 19:50:54.000000000 +0100
@@ -17,7 +17,7 @@
 #include <string.h>
 #include "tcl.h"
 #include "errcode.h"
-#include "slx.h"
+#include <slx.h>
 
 
 /* prototypes: */
@@ -311,8 +311,8 @@
 
   Tcl_SetVar(interp, vname, vval, TCL_LEAVE_ERR_MSG | TCL_GLOBAL_ONLY);
 
-  Tcl_CreateCommand(interp, "shaderScan", ayslx_scanslxtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "shaderScan", (Tcl_CmdProc *)ayslx_scanslxtcmd,
+		    NULL, NULL);
 
   ay_error(AY_EOUTPUT, fname,
 	   "Plug-In 'ayslx' loaded.");
