--- code/sys/sys_main.c.orig	2011-12-24 12:29:37 UTC
+++ code/sys/sys_main.c
@@ -49,6 +49,7 @@ Foundation, Inc., 51 Franklin St, Fifth 
 
 static char binaryPath[ MAX_OSPATH ] = { 0 };
 static char installPath[ MAX_OSPATH ] = { 0 };
+static char libPath[ MAX_OSPATH ] = { 0 };
 
 /*
 =================
@@ -95,6 +96,29 @@ char *Sys_DefaultInstallPath(void)
 
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
+/*
+=================
 Sys_DefaultAppPath
 =================
 */
@@ -490,6 +514,14 @@ void Sys_ParseArgs( int argc, char **arg
 #	endif
 #endif
 
+#ifndef DEFAULT_LIBDIR
+#	ifdef MACOS_X
+#		define DEFAULT_LIBDIR Sys_StripAppBundle(Sys_BinaryPath())
+#	else
+#		define DEFAULT_LIBDIR Sys_BinaryPath()
+#	endif
+#endif
+
 /*
 =================
 Sys_SigHandler
@@ -564,6 +596,7 @@ int main( int argc, char **argv )
 	Sys_ParseArgs( argc, argv );
 	Sys_SetBinaryPath( Sys_Dirname( argv[ 0 ] ) );
 	Sys_SetDefaultInstallPath( DEFAULT_BASEDIR );
+	Sys_SetDefaultLibPath( DEFAULT_LIBDIR );
 
 	// Concatenate the command line for passing to Com_Init
 	for( i = 1; i < argc; i++ )
