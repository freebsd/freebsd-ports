--- src/filter/pfsextractchannels.cpp.orig	2005-06-15 13:36:54.000000000 +0000
+++ src/filter/pfsextractchannels.cpp	2014-02-20 19:04:01.556587853 +0000
@@ -46,7 +46,7 @@
     "See man page for more information.\n" );
 }
 
-static void errorCheck( bool condition, char *string )
+static void errorCheck( bool condition, char const *string )
 {
     if( !condition ) {
 	fprintf( stderr, PROG_NAME " error: %s\n", string );
