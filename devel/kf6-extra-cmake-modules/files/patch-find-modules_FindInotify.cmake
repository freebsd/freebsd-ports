--- find-modules/FindInotify.cmake.orig	2025-12-05 13:18:18 UTC
+++ find-modules/FindInotify.cmake
@@ -56,7 +56,7 @@ if(Inotify_INCLUDE_DIRS)
         cmake_path(GET Inotify_INCLUDE_DIRS PARENT_PATH includes_prefix)
         cmake_path(GET Inotify_LIBRARIES PARENT_PATH lib_prefix)
         cmake_path(GET lib_prefix PARENT_PATH lib_prefix)
-        cmake_path(COMPARE includes_prefix EQUAL lib_prefix prefixes_match)
+        cmake_path(COMPARE ${includes_prefix} EQUAL ${lib_prefix} prefixes_match)
 
         if(NOT prefixes_match)
             set(Inotify_FOUND TRUE)
