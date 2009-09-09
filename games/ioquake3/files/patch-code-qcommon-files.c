--- code/qcommon/files.c.orig	2009-08-30 22:58:50.000000000 +0200
+++ code/qcommon/files.c	2009-08-30 23:10:53.000000000 +0200
@@ -241,6 +241,9 @@
 #endif
 
 static	cvar_t		*fs_basepath;
+#ifdef __FreeBSD__
+static	cvar_t		*fs_libpath;
+#endif
 static	cvar_t		*fs_basegame;
 static	cvar_t		*fs_gamedirvar;
 static	searchpath_t	*fs_searchpaths;
@@ -2761,6 +2764,10 @@
 	fs_debug = Cvar_Get( "fs_debug", "0", 0 );
 	fs_basepath = Cvar_Get ("fs_basepath", Sys_DefaultInstallPath(), CVAR_INIT );
 	fs_basegame = Cvar_Get ("fs_basegame", "", CVAR_INIT );
+	#ifdef __FreeBSD__
+	fs_libpath = Cvar_Get ("fs_libpath", Sys_DefaultLibPath(), CVAR_INIT );
+	#endif
+	
 	homePath = Sys_DefaultHomePath();
 	if (!homePath || !homePath[0]) {
 		homePath = fs_basepath->string;
