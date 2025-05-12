--- src/game_launcher.cpp.orig	2025-02-17 21:50:08 UTC
+++ src/game_launcher.cpp
@@ -61,7 +61,8 @@
 #ifdef _WIN32
 #include <boost/process/windows.hpp>
 #endif
-#include <boost/process.hpp>
+#define BOOST_PROCESS_VERSION 1
+#include <boost/process/v1/child.hpp>
 #include <cstdlib>   // for system
 #include <new>
 #include <utility> // for pair
