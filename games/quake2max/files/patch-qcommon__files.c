--- ./qcommon/files.c.orig	Wed Jan  4 07:14:49 2006
+++ ./qcommon/files.c	Fri Jul 28 13:30:29 2006
@@ -778,6 +778,9 @@
 		Cvar_FullSet ("gamedir", dir, CVAR_SERVERINFO|CVAR_NOSET);
 		if (fs_cddir->string[0])
 			FS_AddGameDirectory (va("%s/%s", fs_cddir->string, dir) );
+#ifdef DATADIR
+		FS_AddGameDirectory(va("%s/%s", DATADIR, dir));
+#endif
 #ifdef LIBDIR
 		FS_AddGameDirectory(va("%s/%s", LIBDIR, dir));
 #endif
@@ -1002,16 +1005,7 @@
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
 
@@ -1027,8 +1021,11 @@
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
