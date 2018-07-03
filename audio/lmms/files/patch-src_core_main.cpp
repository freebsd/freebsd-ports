--- src/core/main.cpp.orig	2018-07-02 13:15:50 UTC
+++ src/core/main.cpp
@@ -156,7 +156,7 @@ int main( int argc, char * * argv )
 	"License as published by the Free Software Foundation; either\n"
 	"version 2 of the License, or (at your option) any later version.\n\n"
 	"Try \"%s --help\" for more information.\n\n", LMMS_VERSION,
-				PLATFORM, MACHINE, QT_VERSION_STR, GCC_VERSION,
+				PLATFORM, MACHINE, QT_VERSION_STR, __VERSION__,
 				argv[0] );
 
 			return( EXIT_SUCCESS );
