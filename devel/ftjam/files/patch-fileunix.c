--- fileunix.c.orig	2014-08-07 15:16:40.000000000 +0200
+++ fileunix.c	2014-08-07 15:18:11.000000000 +0200
@@ -51,6 +51,11 @@
 #   include <sys/stat.h>
 # endif
 
+# if defined( OS_FREEBSD )
+# include <sys/types.h>
+# include <unistd.h>
+# endif
+
 # if defined( OS_RHAPSODY ) || \
      defined( OS_MACOSX ) || \
      defined( OS_NEXT )
@@ -141,7 +146,7 @@
 	if( DEBUG_BINDSCAN )
 	    printf( "scan directory %s\n", dir );
 
-	while( dirent = readdir( d ) )
+	while( ( dirent = readdir( d ) ) )
 	{
 # ifdef old_sinix
 	    /* Broken structure definition on sinix. */
