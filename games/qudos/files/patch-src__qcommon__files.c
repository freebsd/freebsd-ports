--- src/qcommon/files.c.orig	Fri Jun  2 12:50:53 2006
+++ src/qcommon/files.c	Thu Jul 27 17:11:03 2006
@@ -1377,6 +1377,9 @@
 		Cvar_FullSet("gamedir", dir, CVAR_SERVERINFO | CVAR_NOSET);
 		if (fs_cddir->string[0] == '\0')
 			FS_AddGameDirectory(va("%s/%s", fs_cddir->string, dir));
+#ifdef DATADIR
+		FS_AddGameDirectory(va("%s/%s", DATADIR, dir));
+#endif
 #ifdef LIBDIR
 		FS_AddGameDirectory(va("%s/%s", LIBDIR, dir));
 #endif
@@ -1707,11 +1710,7 @@
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
@@ -1731,6 +1730,9 @@
 	fs_homepath = Cvar_Get("homepath", Sys_GetCurrentDirectory(), CVAR_NOSET);
 
 	/* Add baseq2 to search path. */
+#ifdef DATADIR
+	FS_AddGameDirectory(va("%s/" BASEDIRNAME, DATADIR));
+#endif
 #ifdef LIBDIR
 	FS_AddGameDirectory(va("%s/" BASEDIRNAME, LIBDIR));
 #endif
