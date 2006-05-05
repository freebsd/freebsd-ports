--- ./sv_ccmds.c.orig	Thu May 19 17:56:13 2005
+++ ./sv_ccmds.c	Sun Feb 26 11:23:56 2006
@@ -589,7 +589,8 @@
 	SV_Map (false, Cmd_Argv(1), false );
 
 	// archive server state
-	strncpy (svs.mapcmd, Cmd_Argv(1), sizeof(svs.mapcmd)-1);
+	if (Cmd_Argv(1)[0] != '\0')
+		strncpy (svs.mapcmd, Cmd_Argv(1), sizeof(svs.mapcmd)-1);
 
 	// copy off the level to the autosave slot
 	if (!dedicated->intvalue && !Cvar_IntValue ("deathmatch"))
