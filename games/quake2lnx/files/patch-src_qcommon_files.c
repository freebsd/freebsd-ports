--- src/qcommon/files.c.orig	Sun Jan  2 00:38:12 2005
+++ src/qcommon/files.c	Thu Jul 27 17:07:25 2006
@@ -680,6 +680,8 @@
 		Cvar_FullSet ("gamedir", dir, CVAR_SERVERINFO|CVAR_NOSET);
 		if (fs_cddir->string[0])
 			FS_AddGameDirectory (va("%s/%s", fs_cddir->string, dir) );
+		FS_AddGameDirectory (va("%%DATADIR%%/%s", dir));
+		FS_AddGameDirectory (va("%%LIBDIR%%/%s", dir));
 		FS_AddGameDirectory (va("%s/%s", fs_basedir->string, dir) );
 		FS_AddHomeAsGameDirectory(dir);
 	}
@@ -912,6 +914,8 @@
 	//
 	// add baseq2 to search path
 	//
+	FS_AddGameDirectory ("%%DATADIR%%/"BASEDIRNAME);
+	FS_AddGameDirectory ("%%LIBDIR%%/"BASEDIRNAME);
 	FS_AddGameDirectory (va("%s/"BASEDIRNAME, fs_basedir->string) );
 
 	//
