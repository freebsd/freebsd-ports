--- gl_screen.c.orig	Wed Sep  7 11:10:32 2005
+++ gl_screen.c	Mon Jan 16 20:20:05 2006
@@ -734,8 +734,9 @@
 void SCR_ScreenShot_f (void) 
 {
 	int	i, success;
-	char	name[MAX_OSPATH], ext[4], *sshot_dir = "joequake/shots";
+	char	name[MAX_OSPATH], ext[4], sshot_dir[MAX_OSPATH];
 
+	snprintf(sshot_dir, sizeof(sshot_dir), "%s/shots", com_gamedir);
 	if (Cmd_Argc() == 2)
 	{
 		Q_strncpyz (name, Cmd_Argv(1), sizeof(name));
@@ -753,7 +754,7 @@
 		for (i=0 ; i<999 ; i++) 
 		{ 
 			Q_snprintfz (name, sizeof(name), "joequake%03i.%s", i, ext);
-			if (Sys_FileTime(va("%s/%s/%s", com_basedir, sshot_dir, name)) == -1)
+			if (Sys_FileTime(va("%s/%s", sshot_dir, name)) == -1)
 				break;	// file doesn't exist
 		} 
 
@@ -769,7 +770,7 @@
 		return;
 	}
 
-	success = SCR_ScreenShot (va("%s/%s", sshot_dir, name));
+	success = SCR_ScreenShot(va("%s/%s", sshot_dir, name));
 	Con_Printf ("%s %s\n", success ? "Wrote" : "Couldn't write", name);
 } 
 
