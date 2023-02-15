--- unix/unix_glimp.c.orig	2006-06-03 19:24:54 UTC
+++ unix/unix_glimp.c
@@ -31,16 +31,19 @@ Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 #include <signal.h>
 #include <dlfcn.h>
 
-#include "../renderer/r_local.h"
-#include "../client/cl_local.h"
+#include "../shared/shared.h"
 #include "unix_glimp.h"
 #include "unix_local.h"
+#include "x11_linux.h"
 
 static qBool    vid_queueRestart;
 static qBool    vid_isActive;
 
 glxState_t glxState = {.OpenGLLib = NULL};
 
+static void *cmd_vid_restart;
+static void *cmd_listremaps;
+
 /*
 =============================================================================
 
@@ -208,8 +211,8 @@ void VID_Init (refConfig_t *outConfig)
 	vid_fullscreen = Cvar_Register ("vid_fullscreen", "0", CVAR_ARCHIVE);
 
 	// Add some console commands that we want to handle
-	Cmd_AddCommand (qFalse, "vid_restart", VID_Restart_f, "Restarts refresh and media");
-	Cmd_AddCommand (qFalse, "listremaps", ListRemaps_f, "Lists what keys are remapped to AUX* bindings");
+	cmd_vid_restart = Cmd_AddCommand ("vid_restart", VID_Restart_f, "Restarts refresh and media");
+	cmd_listremaps = Cmd_AddCommand ("listremaps", ListRemaps_f, "Lists what keys are remapped to AUX* bindings");
 
 	// Start the graphics mode and load refresh DLL
 	vid_isActive = qFalse;
@@ -232,8 +235,8 @@ void VID_Shutdown (void)
 		vid_isActive = qFalse;
 	}
 
-	Cmd_RemoveCommand ("vid_restart", NULL);
-	Cmd_RemoveCommand ("listremaps", NULL);
+	Cmd_RemoveCommand ("vid_restart", cmd_vid_restart);
+	Cmd_RemoveCommand ("listremaps", cmd_listremaps);
 }
 
 /*
