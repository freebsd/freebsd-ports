--- libslparse/parsenode.cpp.orig	Tue May 14 12:53:14 2002
+++ libslparse/parsenode.cpp	Sat Oct 12 14:11:49 2002
@@ -118,7 +118,7 @@
 	for ( i = 0; i < Type_Last; i++ )
 	{
 		if ( gVariableTypeIdentifiers[ i ][ 0 ] == Id ||
-#if defined(AQSIS_SYSTEM_MACOSX) || defined (AQSIS_SYSTEM_BEOS)
+#if defined(AQSIS_SYSTEM_MACOSX) || defined (AQSIS_SYSTEM_BEOS) || defined(__FreeBSD__)
 		        gVariableTypeIdentifiers[ i ][ 0 ] == tolower( Id ) )
 #else
 				gVariableTypeIdentifiers[ i ][ 0 ] == _tolower( Id ) )
