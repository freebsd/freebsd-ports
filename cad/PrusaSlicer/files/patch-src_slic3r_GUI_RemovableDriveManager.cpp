--- src/slic3r/GUI/RemovableDriveManager.cpp.orig	2025-04-10 11:26:51 UTC
+++ src/slic3r/GUI/RemovableDriveManager.cpp
@@ -35,8 +35,16 @@
 #include <pwd.h>
 #include <boost/filesystem.hpp>
 #include <boost/system/error_code.hpp>
+#if BOOST_VERSION >= 108800 // v2 is now default
+#define BOOST_PROCESS_VERSION 1
+#include <boost/process/v1/child.hpp>
+#include <boost/process/v1/io.hpp>
+//#include <boost/process/v1/pipe.hpp>
+#include <boost/process/v1/search_path.hpp>
+#else
 #include <boost/process.hpp>
 #endif
+#endif
 
 namespace Slic3r {
 namespace GUI { 
@@ -743,7 +751,7 @@ namespace search_for_drives_internal 
 		//confirms if the file is removable drive and adds it to vector
 
 		if (
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 			// Chromium mounts removable drives in a way that produces the same device ID.
 			platform_flavor() == PlatformFlavor::LinuxOnChromium ||
 #endif
