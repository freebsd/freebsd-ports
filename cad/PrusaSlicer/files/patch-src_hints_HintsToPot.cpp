--- src/hints/HintsToPot.cpp.orig	2022-11-13 19:31:07 UTC
+++ src/hints/HintsToPot.cpp
@@ -2,6 +2,7 @@
 #include <vector>
 #include <string>
 #include <boost/filesystem.hpp>
+#include <boost/filesystem/fstream.hpp>
 #include <boost/dll.hpp>
 #include <boost/property_tree/ini_parser.hpp>
 #include <boost/nowide/fstream.hpp>
