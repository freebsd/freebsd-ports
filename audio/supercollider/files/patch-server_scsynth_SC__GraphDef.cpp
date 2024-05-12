--- server/scsynth/SC_GraphDef.cpp.orig	2024-03-15 10:33:57 UTC
+++ server/scsynth/SC_GraphDef.cpp
@@ -46,7 +46,7 @@
 #include <string>
 
 #include <boost/filesystem/operations.hpp> // recursive_directory_iterator
-#include <boost/filesystem/string_file.hpp> // load_string_file
+#include "string_file.hpp" // load_string_file
 
 namespace bfs = boost::filesystem;
 
