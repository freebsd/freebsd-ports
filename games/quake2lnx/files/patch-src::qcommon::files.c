--- src/qcommon/files.c.orig	Wed Oct  9 03:54:25 2002
+++ src/qcommon/files.c	Sat Jun 28 12:30:57 2003
@@ -898,7 +898,11 @@
 	// basedir <path>
 	// allows the game to run from outside the data tree
 	//
+#ifdef DEDICATED_ONLY
 	fs_basedir = Cvar_Get ("basedir", ".", CVAR_NOSET);
+#else
+	fs_basedir = Cvar_Get ("basedir", "%%%%BASEDIR%%%%", CVAR_NOSET);
+#endif
 
 	//
 	// cddir <path>
