Hunk 1: Suppress a lot of warnings for Clang when building PySide6.
Hunk 2: We don't need bash for a simple export command.

--- cmake/ShibokenHelpers.cmake.orig	2024-12-17 09:51:38 UTC
+++ cmake/ShibokenHelpers.cmake
@@ -55,7 +55,7 @@ else()
 else()
     set (gcc_warnings_options "-Wall -Wextra -Wno-strict-aliasing")
     # Clang has -Wno-bad-function-cast, but does not need it.
-    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL  "GNU")
+    if ("${CMAKE_CXX_COMPILER_ID}" MATCHES GNU|Clang)
         set (gcc_warnings_options "${gcc_warnings_options} -Wno-cast-function-type")
     endif()
     if(CMAKE_HOST_UNIX AND NOT CYGWIN)
@@ -774,7 +774,7 @@ $@")
 $@")
     else()
         string(REPLACE ";" ":" path_dirs_native "${path_dirs_native}")
-        file(WRITE "${wrapper_path}" "#!/bin/bash
+        file(WRITE "${wrapper_path}" "#!/bin/sh
 export LD_LIBRARY_PATH=${path_dirs_native}:$LD_LIBRARY_PATH
 $@")
     endif()
