--- qcommon/files.c.orig	2006-01-04 10:33:05 UTC
+++ qcommon/files.c
@@ -775,6 +775,9 @@ void FS_SetGamedir (char *dir)
 		if (fs_cddir->string[0])
 		
 		FS_AddGameDirectory (va("%s/%s", fs_cddir->string, dir) );
+#ifdef DATADIR
+		FS_AddGameDirectory(va("%s/%s", DATADIR, dir));
+#endif
 #ifdef LIBDIR
 		FS_AddGameDirectory(va("%s/%s", LIBDIR, dir));
 #endif
@@ -999,16 +1002,7 @@ void FS_InitFilesystem (void)
 	// basedir <path>
 	// allows the game to run from outside the data tree
 	//
-#if defined __unix__ 
-#ifdef DATADIR
-	fs_basedir = Cvar_Get("basedir", DATADIR, CVAR_NOSET);
-#else
 	fs_basedir = Cvar_Get("basedir", ".", CVAR_NOSET);
-#endif
-#endif
-#ifdef _WIN32
-	fs_basedir = Cvar_Get ("basedir", ".", CVAR_NOSET);
-#endif
 
 	sv_defaultpaks = Cvar_Get ("sv_defaultpaks", "0", CVAR_ARCHIVE);
 
@@ -1024,8 +1018,11 @@ void FS_InitFilesystem (void)
 	//
 	// start up with baseq2 by default
 	//
+#ifdef DATADIR
+	FS_AddGameDirectory (va("%s/"BASEDIRNAME, DATADIR) );
+#endif
 #ifdef LIBDIR
-	FS_AddGameDirectory (va("%s/"BASEDIRNAME, fs_basedir->string) );
+	FS_AddGameDirectory (va("%s/"BASEDIRNAME, LIBDIR) );
 #endif
 	FS_AddGameDirectory(va("%s/"BASEDIRNAME, fs_basedir->string));
 #ifdef DATADIR
