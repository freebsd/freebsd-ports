--- src/files.c.orig	Sun Feb 23 09:12:37 2003
+++ src/files.c	Thu Jul 27 17:05:41 2006
@@ -721,6 +721,8 @@
 		Cvar_FullSet ("gamedir", dir, CVAR_SERVERINFO|CVAR_NOSET);
 		if (fs_cddir->string[0])
 			FS_AddGameDirectory (va("%s/%s", fs_cddir->string, dir) );
+		FS_AddGameDirectory(PKGDATADIR"/"BASEDIRNAME);
+		FS_AddGameDirectory(PKGLIBDIR"/"BASEDIRNAME);
 		FS_AddGameDirectory (va("%s/%s", fs_basedir->string, dir) );
 		FS_AddHomeAsGameDirectory (dir);
 	}
@@ -953,9 +955,9 @@
 	//
 	// add baseq2 to search path
 	//
-	/*FS_AddGameDirectory (va("%s/"BASEDIRNAME, fs_basedir->string) );*/
-	FS_AddGameDirectory(PKGLIBDIR"/"BASEDIRNAME);
 	FS_AddGameDirectory(PKGDATADIR"/"BASEDIRNAME);
+	FS_AddGameDirectory(PKGLIBDIR"/"BASEDIRNAME);
+	FS_AddGameDirectory (va("%s/"BASEDIRNAME, fs_basedir->string) );
 
 	//
 	// then add a '.quake2/baseq2' directory in home directory by default
