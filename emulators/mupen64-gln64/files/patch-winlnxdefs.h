--- winlnxdefs.h.orig	Thu Oct 16 01:01:08 2003
+++ winlnxdefs.h	Wed Sep 22 05:32:54 2004
@@ -30,7 +30,9 @@
 #ifndef WINLNXDEFS_H
 #define WINLNXDEFS_H
 
+#ifndef __FreeBSD__
 #include <features.h>	// we want GNU extensions
+#endif
 #include <dlfcn.h>
 #include <errno.h>
 #include <limits.h> // PATH_MAX
@@ -113,7 +115,11 @@
 	{
 		fprintf( stderr, "(WW) Couldn't get path of .so, trying to get emulator's path\n" );
 #endif // __USE_GNU
+#ifndef __FreeBSD__
 		if (readlink( "/proc/self/exe", path, PATH_MAX ) == -1)
+#else
+		if (readlink( "/proc/curproc/file", path, PATH_MAX ) == -1)
+#endif // __FreeBSD__
 		{
 			fprintf( stderr, "(WW) readlink() /proc/self/exe failed: %s\n", strerror( errno ) );
 			path[0] = '.';
