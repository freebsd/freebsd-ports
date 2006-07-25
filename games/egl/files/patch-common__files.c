--- common/files.c.orig	Mon Jul 24 13:37:31 2006
+++ common/files.c	Mon Jul 24 13:40:31 2006
@@ -1258,6 +1258,23 @@
 		return BASE_MODDIRNAME;
 }
 
+#ifdef HOMEDIR
+/*
+ * FS_AddHomeAsGameDirectory
+ * Add a game directory in "~/.egl". It can be used to set the last path, so
+ * it will be used for writting.
+ */
+void FS_AddHomeAsGameDirectory(char *dir)
+{
+	char	gdir[MAX_OSPATH];	/* Game directory. */
+	char	*homedir;		/* Home directory. */
+
+	if ((homedir = getenv("HOME")) != NULL) {
+		Q_snprintfz(gdir, sizeof(gdir), "%s/.egl/%s", homedir, dir);
+		FS_AddGameDirectory(gdir, dir);
+	}
+}
+#endif
 
 /*
 ================
@@ -1314,10 +1331,17 @@
 	}
 	else {
 		Cvar_VariableSet (fs_gamedircvar, dir, qTrue);
+#ifdef __FreeBSD__
+		FS_AddGameDirectory (Q_VarArgs ("%s/%s", DATADIR, dir), dir);
+		FS_AddGameDirectory (Q_VarArgs ("%s/%s", LIBDIR, dir), dir);
+#endif
 		if (fs_cddir->string[0])
 			FS_AddGameDirectory (Q_VarArgs ("%s/%s", fs_cddir->string, dir), dir);
 
 		FS_AddGameDirectory (Q_VarArgs ("%s/%s", fs_basedir->string, dir), dir);
+#ifdef HOMEDIR
+		FS_AddHomeAsGameDirectory(dir);
+#endif
 	}
 
 	// Store a copy of the search paths inverted for FS_FindFiles
@@ -1693,10 +1717,17 @@
 	fs_defaultPaks	= Cvar_Register ("fs_defaultPaks",	"1",	CVAR_ARCHIVE);
 
 	// Load pak files
+#ifdef __FreeBSD__
+	FS_AddGameDirectory (Q_VarArgs ("%s/"BASE_MODDIRNAME, DATADIR), BASE_MODDIRNAME);
+	FS_AddGameDirectory (Q_VarArgs ("%s/"BASE_MODDIRNAME, LIBDIR), BASE_MODDIRNAME);
+#endif
 	if (fs_cddir->string[0])
 		FS_AddGameDirectory (Q_VarArgs ("%s/"BASE_MODDIRNAME, fs_cddir->string), BASE_MODDIRNAME);
 
 	FS_AddGameDirectory (Q_VarArgs ("%s/"BASE_MODDIRNAME, fs_basedir->string), BASE_MODDIRNAME);
+#ifdef HOMEDIR
+	FS_AddHomeAsGameDirectory(BASE_MODDIRNAME);
+#endif
 
 	// Any set gamedirs will be freed up to here
 	fs_baseSearchPath = fs_searchPaths;
@@ -1704,6 +1735,12 @@
 	// Load the game directory
 	if (fs_game->string[0]) {
 		FS_SetGamedir (fs_game->string, qTrue);
+#ifdef HOMEDIR
+		/* Create the writable directory if doesn't exist ("~/.egl"). */
+		FS_CreatePath(fs_gameDir);
+		Sys_Mkdir(fs_gameDir);
+		Com_Printf(0, "Using '%s' for writing.\n", fs_gameDir);
+#endif
 	}
 	else {
 		// Store a copy of the search paths inverted for FS_FindFiles
