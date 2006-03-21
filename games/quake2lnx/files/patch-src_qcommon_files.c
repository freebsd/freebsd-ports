--- src/qcommon/files.c.orig	Tue Mar 21 19:36:01 2006
+++ src/qcommon/files.c	Tue Mar 21 19:41:27 2006
@@ -913,6 +913,8 @@
 	// add baseq2 to search path
 	//
 	FS_AddGameDirectory (va("%s/"BASEDIRNAME, fs_basedir->string) );
+	FS_AddGameDirectory ("%%LIBDIR%%/"BASEDIRNAME);
+	FS_AddGameDirectory ("%%DATADIR%%/"BASEDIRNAME);
 
 	//
 	// then add a '.quake2/baseq2' directory in home directory by default
