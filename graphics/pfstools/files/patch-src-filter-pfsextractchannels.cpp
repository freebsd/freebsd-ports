--- src/filter/pfsextractchannels.cpp.orig	2005-06-15 13:36:54 UTC
+++ src/filter/pfsextractchannels.cpp
@@ -46,7 +46,7 @@ void printHelp()
     "See man page for more information.\n" );
 }
 
-static void errorCheck( bool condition, char *string )
+static void errorCheck( bool condition, char const *string )
 {
     if( !condition ) {
 	fprintf( stderr, PROG_NAME " error: %s\n", string );
