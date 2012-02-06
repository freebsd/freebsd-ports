--- src/Mesh.cpp.orig	2012-02-06 16:12:15.000000000 +0100
+++ src/Mesh.cpp	2012-02-06 16:14:59.000000000 +0100
@@ -18,6 +18,7 @@
 #include "Mesh.h"
 #include "FileVrml1.h"
 #include "FileVrml2.h"
+#include "FileSTL.h"
 #include <fstream>
 #include <iostream>
 
@@ -173,6 +174,12 @@
 	{
 		file_format = INVENTOR_FILE;
 	}
+	// STL extension
+	else if( extension == "STL" || extension == "stl" )
+	{
+		file_format = STL_FILE;
+	}
+
 	// Other extension
 	else
 	{
@@ -194,6 +201,10 @@
 		case VRML_2_FILE :
 			return ReadVrml2( *this, file_name );
 
+		// STL file
+		case STL_FILE:
+			return ReadSTL( *this, file_name );
+
 		// Other file
 		default :
 			// Unknown file format
