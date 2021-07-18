--- third_party/luajit/cmake/SetVersion.cmake.orig	2021-04-19 14:24:28 UTC
+++ third_party/luajit/cmake/SetVersion.cmake
@@ -4,7 +4,7 @@
 # Copyright (C) 2015-2020 IPONWEB Ltd.
 
 function(SetVersion version majver minver patchver tweakver prerel)
-  find_package(Git QUIET REQUIRED)
+  find_package(Git QUIET)
   if(EXISTS ${CMAKE_SOURCE_DIR}/.git AND Git_FOUND)
     # Read version from the project's VCS and store the result
     # into version.
