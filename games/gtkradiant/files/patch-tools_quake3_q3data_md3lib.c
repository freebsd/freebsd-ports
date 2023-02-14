--- tools/quake3/q3data/md3lib.c.orig	2006-02-10 22:01:20 UTC
+++ tools/quake3/q3data/md3lib.c
@@ -25,10 +25,6 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 #endif
 #include "md3lib.h"
 
-#if defined (__linux__) || defined (__APPLE__)
-#define filelength Q_filelength
-#endif
-
 /*
 ** MD3_ComputeTagFromTri
 */
@@ -149,8 +145,8 @@ void MD3_Dump( const char *filename )
 		Error( "Unable to open '%s'\n", filename );
 	}
 
-	fileSize = filelength( fileno( fp ) );
-	_buffer = malloc( filelength( fileno( fp ) ) );
+	fileSize = Q_filelength( fp );
+	_buffer = malloc( fileSize );
 	fread( _buffer, fileSize, 1, fp );
 	fclose( fp );
 
