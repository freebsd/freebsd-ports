--- ./qcommon/files.c.orig	Sun Dec 31 14:01:34 2006
+++ ./qcommon/files.c	Fri Jan  5 15:51:13 2007
@@ -1090,9 +1090,6 @@
 	int ndirs;
 	char *tmp;
 	//VoiD -E- *.pak support
-	
-	// Create directory if it does not exist
-	Sys_Mkdir(fs_gamedir);
 
 	strcpy(fs_gamedir, dir);
 
@@ -1443,6 +1440,9 @@
 		Cvar_FullSet ("gamedir", dir, CVAR_SERVERINFO|CVAR_NOSET);
 		if (fs_cddir->string[0])
 			FS_AddGameDirectory (va("%s/%s", fs_cddir->string, dir) );
+#if defined(DATADIR)
+		FS_AddGameDirectory(va("%s/%s", DATADIR, dir));
+#endif
 #if defined(LIBDIR)
 		FS_AddGameDirectory(va("%s/%s", LIBDIR, dir));
 #endif
@@ -1777,11 +1777,8 @@
 	// basedir <path>
 	// allows the game to run from outside the data tree
 	//
-#if defined(DATADIR)
-	fs_basedir = Cvar_Get ("basedir", DATADIR, CVAR_NOSET);
-#else
 	fs_basedir = Cvar_Get ("basedir", ".", CVAR_NOSET);
-#endif
+
 	//
 	// cddir <path>
 	// Logically concatenates the cddir after the basedir for 
@@ -1794,6 +1791,9 @@
 	//
 	// start up with baseq2 by default
 	//
+#if defined(DATADIR)
+	FS_AddGameDirectory(va("%s/"BASEDIRNAME, DATADIR));
+#endif
 #if defined(LIBDIR)
 	FS_AddGameDirectory(va("%s/"BASEDIRNAME, LIBDIR));
 #endif
@@ -1819,6 +1819,7 @@
 	
 #if defined (__unix__)
 	/* Create directory if it does not exist. */
+	FS_CreatePath(fs_gamedir);
 	Sys_Mkdir(fs_gamedir);
 #endif
 }
