--- code/sys/sys_unix.c.orig	2009-08-30 21:54:20.000000000 +0200
+++ code/sys/sys_unix.c	2009-08-30 22:10:31.000000000 +0200
@@ -56,8 +56,12 @@
 #ifdef MACOS_X
 			Q_strcat( homePath, sizeof( homePath ), "/Library/Application Support/Quake3" );
 #else
+#ifdef __FreeBSD__
+			Q_strcat( homePath, sizeof( homePath ), HOMEPATH );
+#else
 			Q_strcat( homePath, sizeof( homePath ), "/.q3a" );
 #endif
+#endif
 			if( mkdir( homePath, 0777 ) )
 			{
 				if( errno != EEXIST )
