--- src/slic3r/Config/Snapshot.cpp.orig	2024-12-20 11:54:34 UTC
+++ src/slic3r/Config/Snapshot.cpp
@@ -12,6 +12,7 @@
 #include <boost/property_tree/ini_parser.hpp>
 #include <boost/property_tree/ptree_fwd.hpp>
 #include <boost/filesystem/operations.hpp>
+#include <boost/filesystem/directory.hpp>
 #include <boost/log/trivial.hpp>
 
 #include "libslic3r/PresetBundle.hpp"
