--- code/sys/sys_unix.c.orig	2008-11-10 23:55:22 UTC
+++ code/sys/sys_unix.c
@@ -53,7 +53,9 @@ char *Sys_DefaultHomePath(void)
 		if( ( p = getenv( "HOME" ) ) != NULL )
 		{
 			Q_strncpyz( homePath, p, sizeof( homePath ) );
-#ifdef MACOS_X
+#ifdef HOMEPATH
+			Q_strcat( homePath, sizeof( homePath ), HOMEPATH );
+#elif defined MACOS_X
 			Q_strcat( homePath, sizeof( homePath ), "/Library/Application Support/Quake3" );
 #else
 			Q_strcat( homePath, sizeof( homePath ), "/.q3a" );
