--- src/qcommon/files.c.orig	Fri Jun  2 12:50:53 2006
+++ src/qcommon/files.c	Sat Dec 30 10:12:59 2006
@@ -1099,9 +1099,6 @@
 	/* Set game directory. */
 	Q_strncpyz(fs_gamedir, dir, sizeof(fs_gamedir));
 	
-	/* Create directory if it does not exist. */
-	Sys_Mkdir(fs_gamedir);
-	
 	/* Add the directory to the search path. */
 	search = Z_Malloc(sizeof(fsSearchPath_t));
 	Q_strncpyz(search->path, dir, sizeof(search->path));
@@ -1377,6 +1374,9 @@
 		Cvar_FullSet("gamedir", dir, CVAR_SERVERINFO | CVAR_NOSET);
 		if (fs_cddir->string[0] == '\0')
 			FS_AddGameDirectory(va("%s/%s", fs_cddir->string, dir));
+#ifdef DATADIR
+		FS_AddGameDirectory(va("%s/%s", DATADIR, dir));
+#endif
 #ifdef LIBDIR
 		FS_AddGameDirectory(va("%s/%s", LIBDIR, dir));
 #endif
@@ -1707,11 +1707,7 @@
 	/*
 	 * basedir <path> Allows the game to run from outside the data tree.
 	 */
-#ifdef DATADIR
-	fs_basedir = Cvar_Get("basedir", DATADIR, CVAR_NOSET);
-#else
 	fs_basedir = Cvar_Get("basedir", ".", CVAR_NOSET);
-#endif
 
 	/*
 	 * cddir <path> Logically concatenates the cddir after the basedir to
@@ -1731,6 +1727,9 @@
 	fs_homepath = Cvar_Get("homepath", Sys_GetCurrentDirectory(), CVAR_NOSET);
 
 	/* Add baseq2 to search path. */
+#ifdef DATADIR
+	FS_AddGameDirectory(va("%s/" BASEDIRNAME, DATADIR));
+#endif
 #ifdef LIBDIR
 	FS_AddGameDirectory(va("%s/" BASEDIRNAME, LIBDIR));
 #endif
@@ -1748,6 +1747,7 @@
 		FS_SetGamedir(fs_gamedirvar->string);
 
 	/* Create directory if it does not exist. */
+	FS_CreatePath(fs_gamedir);
 	Sys_Mkdir(fs_gamedir);
 
 	Com_Printf("Using '%s' for writing.\n", fs_gamedir);
