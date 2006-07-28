--- qcommon/files.c.orig	Thu Mar 23 06:30:01 2006
+++ qcommon/files.c	Fri Jul 28 14:54:41 2006
@@ -1314,7 +1314,7 @@
 	char	*homedir;		/* Home directory. */
 
 	if ((homedir = getenv("HOME")) != NULL) {
-		Com_sprintf(gdir, sizeof(gdir), "%s/.quake2/%s", homedir, dir);
+		Com_sprintf(gdir, sizeof(gdir), "%s/.kmquake2/%s", homedir, dir);
 		FS_AddGameDirectory(gdir);
 	}
 }
@@ -1468,16 +1468,7 @@
 	// basedir <path>
 	// allows the game to run from outside the data tree
 	//
-#if defined __unix__ 
-#ifdef DATADIR
-	fs_basedir = Cvar_Get("basedir", DATADIR, CVAR_NOSET);
-#else
-	fs_basedir = Cvar_Get("basedir", ".", CVAR_NOSET);
-#endif
-#endif
-#ifdef _WIN32
 	fs_basedir = Cvar_Get ("basedir", ".", CVAR_NOSET);
-#endif
 
 	//
 	// cddir <path>
@@ -1491,11 +1482,14 @@
 	//
 	// start up with baseq2 by default
 	//
-#ifdef LIBDIR // unix
+#ifdef DATADIR
+	FS_AddGameDirectory(va("%s/"BASEDIRNAME, DATADIR));
+#endif
+#ifdef LIBDIR
 	FS_AddGameDirectory(va("%s/"BASEDIRNAME, LIBDIR));
 #endif
 	FS_AddGameDirectory (va("%s/"BASEDIRNAME, fs_basedir->string) );
-#ifdef DATADIR // unix
+#ifdef DATADIR
 	FS_AddHomeAsGameDirectory(BASEDIRNAME);
 #endif
 	// any set gamedirs will be freed up to here
@@ -1512,6 +1506,7 @@
 	
 #ifdef __unix__
 	/* Create directory if it does not exist. */
+	FS_CreatePath(fs_gamedir);
 	Sys_Mkdir(fs_gamedir);
 	
 	Com_Printf("Using '%s' for writing.\n", fs_gamedir);
@@ -1624,11 +1619,14 @@
 		Cvar_FullSet ("gamedir", dir, CVAR_SERVERINFO|CVAR_NOSET);
 		if (fs_cddir->string[0])
 			FS_AddGameDirectory (va("%s/%s", fs_cddir->string, dir) );
+#ifdef DATADIR
+		FS_AddGameDirectory(va("%s/%s", DATADIR, dir));
+#endif
 #ifdef LIBDIR
 		FS_AddGameDirectory(va("%s/%s", LIBDIR, dir));
 #endif
 		FS_AddGameDirectory (va("%s/%s", fs_basedir->string, dir) );
-#if defined(DATADIR) && !defined(_WIN32)	
+#ifdef DATADIR
 		FS_AddHomeAsGameDirectory(dir);
 #endif
 	}
