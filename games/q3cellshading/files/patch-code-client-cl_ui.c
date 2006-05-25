--- code/client/cl_ui.c.orig	Thu May 25 15:41:27 2006
+++ code/client/cl_ui.c	Thu May 25 15:46:39 2006
@@ -1166,7 +1166,7 @@
 		// init for this gamestate
 		VM_Call( uivm, UI_INIT, (cls.state >= CA_AUTHORIZING && cls.state < CA_ACTIVE));
 	}
-	else if (v != UI_API_VERSION) {
+	else if (v != 0 && v != UI_API_VERSION) {
 		Com_Error( ERR_DROP, "User Interface is version %d, expected %d", v, UI_API_VERSION );
 		cls.uiStarted = qfalse;
 	}
