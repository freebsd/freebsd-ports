--- unix/unix_glimp.c.orig	Mon Jul 24 16:42:03 2006
+++ unix/unix_glimp.c	Mon Jul 24 16:47:48 2006
@@ -41,6 +41,9 @@
 
 glxState_t glxState = {.OpenGLLib = NULL};
 
+static void *cmd_vid_restart;
+static void *cmd_listremaps;
+
 /*
 =============================================================================
 
@@ -208,8 +211,8 @@
 	vid_fullscreen = Cvar_Register ("vid_fullscreen", "0", CVAR_ARCHIVE);
 
 	// Add some console commands that we want to handle
-	Cmd_AddCommand (qFalse, "vid_restart", VID_Restart_f, "Restarts refresh and media");
-	Cmd_AddCommand (qFalse, "listremaps", ListRemaps_f, "Lists what keys are remapped to AUX* bindings");
+	cmd_vid_restart = Cmd_AddCommand ("vid_restart", VID_Restart_f, "Restarts refresh and media");
+	cmd_listremaps = Cmd_AddCommand ("listremaps", ListRemaps_f, "Lists what keys are remapped to AUX* bindings");
 
 	// Start the graphics mode and load refresh DLL
 	vid_isActive = qFalse;
@@ -232,8 +235,8 @@
 		vid_isActive = qFalse;
 	}
 
-	Cmd_RemoveCommand ("vid_restart", NULL);
-	Cmd_RemoveCommand ("listremaps", NULL);
+	Cmd_RemoveCommand ("vid_restart", cmd_vid_restart);
+	Cmd_RemoveCommand ("listremaps", cmd_listremaps);
 }
 
 /*
