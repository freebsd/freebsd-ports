--- libslparse/parsenode.cpp.orig	Thu Sep 12 23:56:09 2002
+++ libslparse/parsenode.cpp	Thu Sep 12 23:58:41 2002
@@ -121,7 +121,7 @@
 #if defined(AQSIS_SYSTEM_MACOSX) || defined (AQSIS_SYSTEM_BEOS)
 		        gVariableTypeIdentifiers[ i ][ 0 ] == tolower( Id ) )
 #else
-				gVariableTypeIdentifiers[ i ][ 0 ] == _tolower( Id ) )
+				gVariableTypeIdentifiers[ i ][ 0 ] == tolower( Id ) )
 #endif
 			return ( i );
 	}
