--- src/sidtune.cpp.orig	2010-08-20 11:48:14 UTC
+++ src/sidtune.cpp
@@ -35,7 +35,9 @@ using namespace std;
 #include "myendian.h"
 #include "pp.h"
 
+using namespace std;
 
+
 const char text_songNumberExceed[] = "WARNING: Selected song number was too high";
 const char text_emptyFile[] = "ERROR: File is empty";
 const char text_unrecognizedFormat[] = "ERROR: Could not determine file format";
@@ -307,9 +309,9 @@ udword sidTune::loadFile(const char* fileName, ubyte**
     }
     // Open binary input file stream at end of file.
 #if defined(SID_HAVE_IOS_BIN)
-	ifstream myIn( fileName, ios::in|ios::bin|ios::ate );
+	ifstream myIn( fileName, ios::in|ios::bin );
 #else
-	ifstream myIn( fileName, ios::in|ios::binary|ios::ate );
+	ifstream myIn( fileName, ios::in|ios::binary );
 #endif
 	// As a replacement for !is_open(), bad() and the NOT-operator
     // don't seem to work on all systems.
