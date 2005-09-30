--- extract-xiso.c.orig	Fri Sep 30 15:49:47 2005
+++ extract-xiso.c	Fri Sep 30 15:50:29 2005
@@ -215,7 +215,7 @@
 #include <sys/types.h>
 
 #if defined( __FREEBSD__ )
-	#include <machine/limits.h>
+	#include <limits.h>
 #endif
 
 #if ! defined( NO_FTP )
@@ -1345,6 +1345,11 @@
 	if ( ! err ) {
 		if ( read( in_xiso, dir->filename, dir->filename_length ) != dir->filename_length ) read_err();
 		if ( ! err ) dir->filename[ dir->filename_length ] = 0;
+		if (strstr(dir->filename,"..") || strchr(dir->filename, '/') || strchr(dir->filename, '\\'))
+		{
+			printf("Filename contains invalid characters");
+			exit(1);
+		}
 	}
 	
 	if ( ! err && in_mode == k_generate_avl ) {
