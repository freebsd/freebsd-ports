--- src/qcommon/files.c.orig	Sun Jan  2 00:38:12 2005
+++ src/qcommon/files.c	Tue Sep 27 18:25:41 2005
@@ -912,7 +912,8 @@
 	//
 	// add baseq2 to search path
 	//
-	FS_AddGameDirectory (va("%s/"BASEDIRNAME, fs_basedir->string) );
+	FS_AddGameDirectory(LIBDIR"/"BASEDIRNAME);
+	FS_AddGameDirectory(DATADIR"/"BASEDIRNAME);
 
 	//
 	// then add a '.quake2/baseq2' directory in home directory by default
