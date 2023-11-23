We don't need bash for a simple export command.

--- cmake/ShibokenHelpers.cmake.orig	2023-10-14 09:37:51 UTC
+++ cmake/ShibokenHelpers.cmake
@@ -772,7 +772,7 @@ $@")
 $@")
     else()
         string(REPLACE ";" ":" path_dirs_native "${path_dirs_native}")
-        file(WRITE "${wrapper_path}" "#!/bin/bash
+        file(WRITE "${wrapper_path}" "#!/bin/sh
 export LD_LIBRARY_PATH=${path_dirs_native}:$LD_LIBRARY_PATH
 $@")
     endif()
