--- qcommon/files.c.orig	Sat May 20 09:53:45 2006
+++ qcommon/files.c	Sat May 20 09:59:37 2006
@@ -1232,11 +1232,6 @@
 
 	Q_strncpy (fs_gamedir, dir, sizeof(fs_gamedir)-1);
 
-#if defined (__unix__)
-	// Create directory if it does not exist
-	Sys_Mkdir(fs_gamedir);
-#endif
-
 	Com_DPrintf ("FS_AddGameDirectory: Added '%s'\n", dir);
 
 	//
@@ -1391,6 +1386,17 @@
 		FS_AddGameDirectory (va("%s/%s", fs_basedir->string, dir) );
 }
 
+void FS_AddHomeAsGameDirectory(char *dir)
+{
+	char	gdir[MAX_OSPATH];	/* Game directory. */
+	char	*homedir;		/* Home directory. */
+
+	if ((homedir = getenv("HOME")) != NULL) {
+		Com_sprintf(gdir, sizeof(gdir), "%s/.r1q2/%s", homedir, dir);
+		FS_AddGameDirectory(gdir);
+	}
+}
+
 /*
 ================
 FS_SetGamedir
@@ -1449,7 +1455,10 @@
 	{
 		Com_sprintf (fs_gamedir, sizeof(fs_gamedir), "%s/%s", fs_basedir->string, dir);
 		Cvar_FullSet ("gamedir", dir, CVAR_SERVERINFO|CVAR_NOSET);
+		FS_AddGameDirectory (va("%s/%s", DATADIR, dir) );
+		FS_AddGameDirectory (va("%s/%s", LIBDIR, dir) );
 		FS_AddGameDirectory (va("%s/%s", fs_basedir->string, dir) );
+		FS_AddHomeAsGameDirectory(dir);
 	}
 }
 
@@ -1707,7 +1716,10 @@
 	//
 	// start up with baseq2 by default
 	//
+	FS_AddGameDirectory(va("%s/"BASEDIRNAME, DATADIR));
+	FS_AddGameDirectory(va("%s/"BASEDIRNAME, LIBDIR));
 	FS_AddGameDirectory (va("%s/"BASEDIRNAME, fs_basedir->string) );
+	FS_AddHomeAsGameDirectory(BASEDIRNAME);
 
 	// any set gamedirs will be freed up to here
 	fs_base_searchpaths = fs_searchpaths;
@@ -1716,4 +1728,8 @@
 	fs_gamedirvar = Cvar_Get ("game", "", CVAR_LATCH|CVAR_SERVERINFO);
 	if (fs_gamedirvar->string[0])
 		FS_SetGamedir (fs_gamedirvar->string);
+
+	FS_CreatePath(fs_gamedir);
+	Sys_Mkdir(fs_gamedir);
+	Com_Printf("Using '%s' for writing.\n", LOG_GENERAL, fs_gamedir);
 }
