--- plugins/ayslx.c.orig	2015-06-23 18:03:50 UTC
+++ plugins/ayslx.c
@@ -17,7 +17,7 @@
 #include <string.h>
 #include "tcl.h"
 #include "errcode.h"
-#include "slx.h"
+#include <slx.h>
 
 
 /* prototypes: */
@@ -319,8 +319,8 @@ Ayslx_Init(Tcl_Interp *interp)
 
   Tcl_SetVar(interp, vname, vval, TCL_LEAVE_ERR_MSG | TCL_GLOBAL_ONLY);
 
-  Tcl_CreateCommand(interp, "shaderScan", ayslx_scanslxtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "shaderScan", (Tcl_CmdProc *)ayslx_scanslxtcmd,
+		    NULL, NULL);
 
   ay_error(AY_EOUTPUT, fname,
 	   "Plugin 'ayslx' successfully loaded.");
