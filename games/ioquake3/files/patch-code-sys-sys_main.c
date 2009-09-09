--- code/sys/sys_main.c.orig	2009-08-30 22:32:59.000000000 +0200
+++ code/sys/sys_main.c	2009-08-30 23:21:12.000000000 +0200
@@ -49,6 +49,9 @@
 
 static char binaryPath[ MAX_OSPATH ] = { 0 };
 static char installPath[ MAX_OSPATH ] = { 0 };
+#ifdef __FreeBSD__
+static char libPath[ MAX_OSPATH ] = { 0 };
+#endif
 
 /*
 =================
@@ -93,6 +96,31 @@
 		return Sys_Cwd();
 }
 
+#ifdef __FreeBSD__
+/*
+=================
+Sys_SetDefaultLibPath
+=================
+*/
+void Sys_SetDefaultLibPath(const char *path)
+{
+	Q_strncpyz(libPath, path, sizeof(libPath));
+}
+
+/*
+=================
+Sys_DefaultLibPath
+=================
+*/
+char *Sys_DefaultLibPath(void)
+{
+	if (*libPath)
+		return libPath;
+	else
+		return Sys_Cwd();
+}
+#endif
+
 /*
 =================
 Sys_DefaultAppPath
@@ -384,6 +412,7 @@
 #1 look down current path
 #2 look in fs_homepath
 #3 look in fs_basepath
+#4 look in fs_libpath under FreeBSD
 =================
 */
 void *Sys_LoadDll( const char *name, char *fqpath ,
@@ -394,6 +423,9 @@
 	void  (*dllEntry)( intptr_t (*syscallptr)(intptr_t, ...) );
 	char  fname[MAX_OSPATH];
 	char  *basepath;
+	#ifdef __FreeBSD__
+	char  *libpath;
+	#endif
 	char  *homepath;
 	char  *pwdpath;
 	char  *gamedir;
@@ -405,6 +437,9 @@
 	// TODO: use fs_searchpaths from files.c
 	pwdpath = Sys_Cwd();
 	basepath = Cvar_VariableString( "fs_basepath" );
+	#ifdef __FreeBSD__
+	libpath = Cvar_VariableString( "fs_libpath" );
+	#endif
 	homepath = Cvar_VariableString( "fs_homepath" );
 	gamedir = Cvar_VariableString( "fs_game" );
 
@@ -416,6 +451,11 @@
 	if(!libHandle && basepath)
 		libHandle = Sys_TryLibraryLoad(basepath, gamedir, fname, fqpath);
 
+	#ifdef __FreeBSD__
+	if(!libHandle && libpath)
+		libHandle = Sys_TryLibraryLoad(libpath, gamedir, fname, fqpath);
+	#endif
+
 	if(!libHandle) {
 		Com_Printf ( "Sys_LoadDll(%s) failed to load library\n", name );
 		return NULL;
@@ -469,6 +509,16 @@
 #	endif
 #endif
 
+#ifdef __FreeBSD__
+#ifndef DEFAULT_LIBDIR
+#	ifdef MACOS_X
+#		define DEFAULT_LIBDIR Sys_StripAppBundle(Sys_BinaryPath())
+#	else
+#		define DEFAULT_LIBDIR Sys_BinaryPath()
+#	endif
+#endif
+#endif
+
 /*
 =================
 Sys_SigHandler
@@ -540,6 +590,9 @@
 	Sys_ParseArgs( argc, argv );
 	Sys_SetBinaryPath( Sys_Dirname( argv[ 0 ] ) );
 	Sys_SetDefaultInstallPath( DEFAULT_BASEDIR );
+	#ifdef __FreeBSD__
+	Sys_SetDefaultLibPath( DEFAULT_LIBDIR );
+	#endif
 
 	// Concatenate the command line for passing to Com_Init
 	for( i = 1; i < argc; i++ )
