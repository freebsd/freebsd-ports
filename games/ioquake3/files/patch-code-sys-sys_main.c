--- code/sys/sys_main.c.orig	2009-03-02 22:26:36 UTC
+++ code/sys/sys_main.c
@@ -49,6 +49,7 @@ Foundation, Inc., 51 Franklin St, Fifth 
 
 static char binaryPath[ MAX_OSPATH ] = { 0 };
 static char installPath[ MAX_OSPATH ] = { 0 };
+static char libPath[ MAX_OSPATH ] = { 0 };
 
 /*
 =================
@@ -95,6 +96,30 @@ char *Sys_DefaultInstallPath(void)
 
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
@@ -384,6 +409,7 @@ Used to load a development dll instead o
 #1 look down current path
 #2 look in fs_homepath
 #3 look in fs_basepath
+#4 look in fs_libpath
 =================
 */
 void *Sys_LoadDll( const char *name, char *fqpath ,
@@ -394,6 +420,7 @@ void *Sys_LoadDll( const char *name, cha
 	void  (*dllEntry)( intptr_t (*syscallptr)(intptr_t, ...) );
 	char  fname[MAX_OSPATH];
 	char  *basepath;
+	char  *libpath;
 	char  *homepath;
 	char  *pwdpath;
 	char  *gamedir;
@@ -405,6 +432,7 @@ void *Sys_LoadDll( const char *name, cha
 	// TODO: use fs_searchpaths from files.c
 	pwdpath = Sys_Cwd();
 	basepath = Cvar_VariableString( "fs_basepath" );
+	libpath = Cvar_VariableString( "fs_libpath" );
 	homepath = Cvar_VariableString( "fs_homepath" );
 	gamedir = Cvar_VariableString( "fs_game" );
 
@@ -413,6 +441,9 @@ void *Sys_LoadDll( const char *name, cha
 	if(!libHandle && homepath)
 		libHandle = Sys_TryLibraryLoad(homepath, gamedir, fname, fqpath);
 
+	if(!libHandle && libpath)
+		libHandle = Sys_TryLibraryLoad(libpath, gamedir, fname, fqpath);
+
 	if(!libHandle && basepath)
 		libHandle = Sys_TryLibraryLoad(basepath, gamedir, fname, fqpath);
 
@@ -469,6 +500,10 @@ void Sys_ParseArgs( int argc, char **arg
 #	endif
 #endif
 
+#ifndef DEFAULT_LIBDIR
+#	define DEFAULT_LIBDIR DEFAULT_BASEDIR
+#endif
+
 /*
 =================
 Sys_SigHandler
@@ -540,6 +575,7 @@ int main( int argc, char **argv )
 	Sys_ParseArgs( argc, argv );
 	Sys_SetBinaryPath( Sys_Dirname( argv[ 0 ] ) );
 	Sys_SetDefaultInstallPath( DEFAULT_BASEDIR );
+	Sys_SetDefaultLibPath( DEFAULT_LIBDIR );
 
 	// Concatenate the command line for passing to Com_Init
 	for( i = 1; i < argc; i++ )
