--- src/porting_layer/src/plat_path.c.orig	2013-02-10 19:57:20.000000000 -0500
+++ src/porting_layer/src/plat_path.c	2013-02-10 19:57:35.000000000 -0500
@@ -37,10 +37,10 @@
 		home = getenv( "HOME" );
 		if ( home ) {
 			snprintf( path, path_len, "%s/.chewing" SEARCH_PATH_SEP
-				LIBDIR "/libchewing", home );
+				DATADIR "/chewing", home );
 		} else {
 			// No HOME ?
-			strncpy( path, SEARCH_PATH_SEP LIBDIR "/libchewing", path_len );
+			strncpy( path, SEARCH_PATH_SEP DATADIR "/chewing", path_len );
 		}
 	}
 
