--- unix/x11_main.c.orig	Mon Jul 24 16:51:38 2006
+++ unix/x11_main.c	Mon Jul 24 16:53:17 2006
@@ -51,6 +51,7 @@
 
 cVar_t *in_mouse;
 
+static void *cmd_force_centerview;
 /*
 ==========================================================================
 
@@ -690,7 +691,7 @@
 	// Mouse variables
 	in_dgamouse	= Cvar_Register ("in_dgamouse", "1", CVAR_ARCHIVE);
 
-	Cmd_AddCommand (qFalse, "force_centerview", Force_CenterView_f, "Force the screen to a center view");
+	cmd_force_centerview = Cmd_AddCommand ("force_centerview", Force_CenterView_f, "Force the screen to a center view");
 }
 
 
@@ -701,7 +702,7 @@
 */
 void IN_Shutdown (void)
 {
-	Cmd_RemoveCommand ("force_centerview", NULL);
+	Cmd_RemoveCommand ("force_centerview", cmd_force_centerview);
 }
 
 
