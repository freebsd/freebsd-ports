--- cmake/modules/FindLoudmouth.cmake.orig	2018-11-19 18:18:20.197436000 +0100
+++ cmake/modules/FindLoudmouth.cmake	2018-11-19 18:25:49.793954000 +0100
@@ -13,14 +13,6 @@
   set(LOUDMOUTH_FOUND TRUE)
 
 else ()
-  if(NOT WIN32)
-    # use pkg-config to get the directories and then use these values
-    # in the FIND_PATH() and FIND_LIBRARY() calls
-    find_package(PkgConfig)
-    pkg_search_module(LOUDMOUTH loudmouth-1.0)
-  
-  else()
-
     find_path(LOUDMOUTH_INCLUDE_DIRS loudmouth/loudmouth.h /usr/include/loudmouth-1.0
       ${_LOUDMOUTHIncDir}
     )
@@ -30,8 +22,6 @@
       ${_LOUDMOUTHLinkDir}
     )
 
-  endif()
-
   if (LOUDMOUTH_INCLUDE_DIRS AND LOUDMOUTH_LIBRARIES)
     set(LOUDMOUTH_FOUND TRUE)
   else ()
