--- cmake/modules/FindLoudmouth.cmake.orig	2021-02-13 22:39:45 UTC
+++ cmake/modules/FindLoudmouth.cmake
@@ -13,13 +13,6 @@ if (LOUDMOUTH_INCLUDE_DIRS AND LOUDMOUTH_LIBRARIES)
   set(LOUDMOUTH_FOUND TRUE)
 
 else ()
-  if(NOT WIN32)
-    # use pkg-config to get the directories and then use these values
-    # in the FIND_PATH() and FIND_LIBRARY() calls
-    find_package(PkgConfig)
-    pkg_search_module(LOUDMOUTH loudmouth-1.0)
-  
-  else()
 
     find_path(LOUDMOUTH_INCLUDE_DIRS loudmouth/loudmouth.h /usr/include/loudmouth-1.0
       ${_LOUDMOUTHIncDir}
@@ -29,8 +22,6 @@ else ()
       PATHS
       ${_LOUDMOUTHLinkDir}
     )
-
-  endif()
 
   if (LOUDMOUTH_INCLUDE_DIRS AND LOUDMOUTH_LIBRARIES)
     set(LOUDMOUTH_FOUND TRUE)
