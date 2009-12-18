--- code/sys/sys_unix.c.orig	2008-11-11 00:55:22.000000000 +0100
+++ code/sys/sys_unix.c	2009-12-08 10:54:22.000000000 +0100
@@ -53,7 +53,9 @@
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
