--- ./qcommon/files.c.orig	Thu Mar 23 06:30:01 2006
+++ ./qcommon/files.c	Sat May 20 13:44:43 2006
@@ -1314,7 +1314,7 @@
 	char	*homedir;		/* Home directory. */
 
 	if ((homedir = getenv("HOME")) != NULL) {
-		Com_sprintf(gdir, sizeof(gdir), "%s/.quake2/%s", homedir, dir);
+		Com_sprintf(gdir, sizeof(gdir), "%s/.kmquake2/%s", homedir, dir);
 		FS_AddGameDirectory(gdir);
 	}
 }
@@ -1512,6 +1512,7 @@
 	
 #ifdef __unix__
 	/* Create directory if it does not exist. */
+	FS_CreatePath(fs_gamedir);
 	Sys_Mkdir(fs_gamedir);
 	
 	Com_Printf("Using '%s' for writing.\n", fs_gamedir);
