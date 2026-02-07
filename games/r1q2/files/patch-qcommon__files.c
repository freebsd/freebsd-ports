--- ./qcommon/files.c.orig	Fri Sep 29 02:06:34 2006
+++ ./qcommon/files.c	Sat Dec 16 17:28:37 2006
@@ -1382,6 +1382,24 @@
 
 /*
 ================
+FS_AddHomeAsGameDirectory
+
+Adds ~/.r1q2/<dir> as a game directory.
+================
+*/
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
+/*
+================
 FS_SetGamedir
 
 Sets the gamedir and path to a different directory.
@@ -1438,7 +1456,10 @@
 	{
 		Com_sprintf (fs_gamedir, sizeof(fs_gamedir), "%s/%s", fs_basedir->string, dir);
 		Cvar_FullSet ("gamedir", dir, CVAR_SERVERINFO|CVAR_NOSET);
+		FS_AddGameDirectory (va("%s/%s", DATADIR, dir) );
+		FS_AddGameDirectory (va("%s/%s", LIBDIR, dir) );
 		FS_AddGameDirectory (va("%s/%s", fs_basedir->string, dir) );
+		FS_AddHomeAsGameDirectory(dir);
 	}
 }
 
@@ -1696,7 +1717,10 @@
 	//
 	// start up with baseq2 by default
 	//
+	FS_AddGameDirectory(va("%s/"BASEDIRNAME, DATADIR));
+	FS_AddGameDirectory(va("%s/"BASEDIRNAME, LIBDIR));
 	FS_AddGameDirectory (va("%s/"BASEDIRNAME, fs_basedir->string) );
+	FS_AddHomeAsGameDirectory(BASEDIRNAME);
 
 	// any set gamedirs will be freed up to here
 	fs_base_searchpaths = fs_searchpaths;
@@ -1705,4 +1729,8 @@
 	fs_gamedirvar = Cvar_Get ("game", "", CVAR_LATCH|CVAR_SERVERINFO);
 	if (fs_gamedirvar->string[0])
 		FS_SetGamedir (fs_gamedirvar->string);
+
+	FS_CreatePath(fs_gamedir);
+	Sys_Mkdir(fs_gamedir);
+	Com_Printf("Using '%s' for writing.\n", LOG_GENERAL, fs_gamedir);
 }
