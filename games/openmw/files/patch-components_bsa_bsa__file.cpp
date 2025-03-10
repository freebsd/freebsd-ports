--- components/bsa/bsa_file.cpp.orig	2023-08-08 09:23:20 UTC
+++ components/bsa/bsa_file.cpp
@@ -26,6 +26,7 @@
 #include <components/files/constrainedfilestream.hpp>
 
 #include <cassert>
+#include <algorithm>
 
 #include <boost/filesystem/path.hpp>
 #include <boost/filesystem/fstream.hpp>
