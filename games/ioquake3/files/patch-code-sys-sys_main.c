--- code/sys/sys_main.c.orig	2009-03-02 23:26:36.000000000 +0100
+++ code/sys/sys_main.c	2009-12-08 11:31:12.000000000 +0100
@@ -49,6 +49,7 @@
 
 static char binaryPath[ MAX_OSPATH ] = { 0 };
 static char installPath[ MAX_OSPATH ] = { 0 };
+static char libPath[ MAX_OSPATH ] = { 0 };
 
 /*
 =================
@@ -95,6 +96,30 @@
 
 /*
 =================
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
+
+
+/*
+=================
 Sys_DefaultAppPath
 =================
 */
@@ -384,6 +409,7 @@
 #1 look down current path
 #2 look in fs_homepath
 #3 look in fs_basepath
+#4 look in fs_libpath
 =================
 */
 void *Sys_LoadDll( const char *name, char *fqpath ,
@@ -394,6 +420,7 @@
 	void  (*dllEntry)( intptr_t (*syscallptr)(intptr_t, ...) );
 	char  fname[MAX_OSPATH];
 	char  *basepath;
+	char  *libpath;
 	char  *homepath;
 	char  *pwdpath;
 	char  *gamedir;
@@ -405,6 +432,7 @@
 	// TODO: use fs_searchpaths from files.c
 	pwdpath = Sys_Cwd();
 	basepath = Cvar_VariableString( "fs_basepath" );
+	libpath = Cvar_VariableString( "fs_libpath" );
 	homepath = Cvar_VariableString( "fs_homepath" );
 	gamedir = Cvar_VariableString( "fs_game" );
 
@@ -413,6 +441,9 @@
 	if(!libHandle && homepath)
 		libHandle = Sys_TryLibraryLoad(homepath, gamedir, fname, fqpath);
 
+	if(!libHandle && libpath)
+		libHandle = Sys_TryLibraryLoad(libpath, gamedir, fname, fqpath);
+
 	if(!libHandle && basepath)
 		libHandle = Sys_TryLibraryLoad(basepath, gamedir, fname, fqpath);
 
@@ -469,6 +500,10 @@
 #	endif
 #endif
 
+#ifndef DEFAULT_LIBDIR
+#	define DEFAULT_LIBDIR DEFAULT_BASEDIR
+#endif
+
 /*
 =================
 Sys_SigHandler
@@ -540,6 +575,7 @@
 	Sys_ParseArgs( argc, argv );
 	Sys_SetBinaryPath( Sys_Dirname( argv[ 0 ] ) );
 	Sys_SetDefaultInstallPath( DEFAULT_BASEDIR );
+	Sys_SetDefaultLibPath( DEFAULT_LIBDIR );
 
 	// Concatenate the command line for passing to Com_Init
 	for( i = 1; i < argc; i++ )
