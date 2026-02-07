--- ./r_screen.c.orig	Sun Jan  8 18:35:00 2006
+++ ./r_screen.c	Sat May 20 10:00:24 2006
@@ -556,8 +556,9 @@
 void SCR_ScreenShot_f (void)
 { 
 	int     i, success;
-	char	name[MAX_OSPATH], ext[4], *sshot_dir = "joequake/shots";
+	char	name[MAX_OSPATH], ext[4], sshot_dir[MAX_OSPATH];
 
+	snprintf(sshot_dir, sizeof(sshot_dir), "%s/shots", com_gamedir);
 	if (Cmd_Argc() == 2)
 	{
 		Q_strncpyz (name, Cmd_Argv(1), sizeof(name));
@@ -573,7 +574,7 @@
 		for (i=0 ; i<999 ; i++)
 		{
 			Q_snprintfz (name, sizeof(name), "joequake%03i.%s", i, ext);
-			if (Sys_FileTime(va("%s/%s/%s", com_basedir, sshot_dir, name)) == -1)
+			if (Sys_FileTime(va("%s/%s", sshot_dir, name)) == -1)
 				break;  // file doesn't exist
 		}
 
