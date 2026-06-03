--- extract-xiso.c.orig	2026-01-25 16:16:29 UTC
+++ extract-xiso.c
@@ -253,10 +253,6 @@
 #include <sys/types.h>
 #include <stdint.h>
 
-#if defined( __FREEBSD__ ) || defined( __OPENBSD__ )
-	#include <machine/limits.h>
-#endif
-
 #if defined( _WIN32 )
 	#include <direct.h>
 	#include "win32/dirent.c"
@@ -286,7 +282,7 @@
 	#define READWRITEFLAGS				O_RDWR
 
 	typedef	off_t						xoff_t;
-#elif defined( __FREEBSD__ )
+#elif defined( __FreeBSD__ )
 	#define exiso_target				"freebsd"
 
 	#define PATH_CHAR					'/'
