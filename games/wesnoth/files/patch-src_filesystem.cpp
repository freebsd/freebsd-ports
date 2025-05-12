--- src/filesystem.cpp.orig	2025-02-17 21:50:08 UTC
+++ src/filesystem.cpp
@@ -30,11 +30,13 @@
 #include "serialization/unicode.hpp"
 #include "utils/general.hpp"
 
+#define BOOST_PROCESS_VERSION 1
 #include <boost/filesystem.hpp>
 #include <boost/filesystem/fstream.hpp>
 #include <boost/iostreams/device/file_descriptor.hpp>
 #include <boost/iostreams/stream.hpp>
-#include <boost/process.hpp>
+#include <boost/process/v1/search_path.hpp>
+#include <boost/algorithm/string/replace.hpp>
 #include "game_config_view.hpp"
 
 #ifdef _WIN32
