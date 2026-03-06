--- src/slic3r/GUI/RemovableDriveManager.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/RemovableDriveManager.cpp
@@ -22,7 +22,14 @@
 #include <pwd.h>
 #include <boost/filesystem.hpp>
 #include <boost/system/error_code.hpp>
+#if BOOST_VERSION >= 108800
+#define BOOST_PROCESS_VERSION 1
+#include <boost/process/v1/child.hpp>
+#include <boost/process/v1/io.hpp>
+#include <boost/process/v1/search_path.hpp>
+#else
 #include <boost/process.hpp>
+#endif
 #endif
 
 namespace Slic3r {
