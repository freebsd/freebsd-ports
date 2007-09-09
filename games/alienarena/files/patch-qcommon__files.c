--- ./qcommon/files.c.orig	Wed Apr 18 14:28:43 2007
+++ ./qcommon/files.c	Sat Jul 21 09:36:05 2007
@@ -776,6 +776,12 @@
 	else
 	{
 		Cvar_FullSet ("gamedir", dir, CVAR_SERVERINFO|CVAR_NOSET);
+#ifdef DATADIR
+		FS_AddGameDirectory (va("%s/%s", DATADIR, dir) );
+#endif
+#ifdef LIBDIR
+		FS_AddGameDirectory (va("%s/%s", LIBDIR, dir) );
+#endif
 		if (fs_cddir->string[0])
 			FS_AddGameDirectory (va("%s/%s", fs_cddir->string, dir) );
 		FS_AddGameDirectory (va("%s/%s", fs_basedir->string, dir) );
@@ -1020,6 +1026,19 @@
 	Cmd_AddCommand ("path", FS_Path_f);
 	Cmd_AddCommand ("link", FS_Link_f);
 	Cmd_AddCommand ("dir", FS_Dir_f );
+
+	//
+	// DATADIR / LIBDIR support.
+	// Both directories are used to load data and libraries from, allowing
+	// different OSes to have them where they want, according to their
+	// conventions.
+	//
+#ifdef DATADIR
+	FS_AddGameDirectory (va("%s/"BASEDIRNAME, DATADIR));
+#endif
+#ifdef LIBDIR
+	FS_AddGameDirectory (va("%s/"BASEDIRNAME, LIBDIR));
+#endif
 
 	//
 	// basedir <path>
