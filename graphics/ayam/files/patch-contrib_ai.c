--- contrib/ai.c.orig	2007-09-21 13:30:37.000000000 +0200
+++ contrib/ai.c	2007-12-17 19:00:20.000000000 +0100
@@ -530,11 +530,11 @@
   /* char fname[] = "Ai_Init";*/
 
    /* Create Tcl commands */
-  Tcl_CreateCommand(interp, "ai_makeInstances", ay_ai_makeinstancestcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "ai_makeInstances", (Tcl_CmdProc *) ay_ai_makeinstancestcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "ai_resolveInstances", ay_ai_resolveinstancestcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "ai_resolveInstances", (Tcl_CmdProc *) ay_ai_resolveinstancestcmd,
+		    NULL, NULL);
   /*
   Tcl_CreateCommand(interp, "ai_getInstancesList", ay_ai_getinstanceslisttcmd,
 		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
