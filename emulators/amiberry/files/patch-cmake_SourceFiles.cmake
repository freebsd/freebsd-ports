--- cmake/SourceFiles.cmake.orig	2025-09-07 17:28:06 UTC
+++ cmake/SourceFiles.cmake
@@ -452,7 +452,7 @@ install(TARGETS ${PROJECT_NAME}
 )

 # Settings for installing per platform
-if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
+if (CMAKE_SYSTEM_NAME STREQUAL "Linux" OR CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
     include(cmake/linux/CMakeLists.txt)
 elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
     include(cmake/macos/CMakeLists.txt)
