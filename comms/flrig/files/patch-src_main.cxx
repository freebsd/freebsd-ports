- fix build on 14 with clang-16 because std::ostringstream::streampos
- doesn't exist there.
- using the C++ standard std::streampos instead.

--- src/main.cxx.orig	2023-07-16 15:55:45 UTC
+++ src/main.cxx
@@ -21,6 +21,7 @@
 #include "config.h"
 
 #include <stdlib.h>
+#include <ios>
 #include <iostream>
 #include <fstream>
 #include <sstream>
@@ -313,7 +314,7 @@ void rotate_log(std::string filename)
 {
 	const int n = 5; // rename existing log files to keep up to 5 old versions
 	ostringstream oldfn, newfn;
-	ostringstream::streampos p;
+	streampos p;
 
 	oldfn << filename << '.';
 	newfn << filename << '.';
