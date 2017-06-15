Always use find_path() and find_library() to find Loudmouth so that the full
paths are always used in the compiler and linker.
--- cmake/modules/FindLoudmouth.cmake.orig	2017-03-27 19:37:41 UTC
+++ cmake/modules/FindLoudmouth.cmake
@@ -13,13 +13,6 @@ if (LOUDMOUTH_INCLUDE_DIRS AND LOUDMOUTH
   SET(LOUDMOUTH_FOUND TRUE)
 
 else (LOUDMOUTH_INCLUDE_DIRS AND LOUDMOUTH_LIBRARIES)
-  if(NOT WIN32)
-    # use pkg-config to get the directories and then use these values
-    # in the FIND_PATH() and FIND_LIBRARY() calls
-    find_package(PkgConfig)
-    PKG_SEARCH_MODULE(LOUDMOUTH loudmouth-1.0)
-  
-  else(NOT WIN32)
 
     FIND_PATH(LOUDMOUTH_INCLUDE_DIRS loudmouth/loudmouth.h /usr/local/include/loudmouth-1.0
       ${_LOUDMOUTHIncDir}
@@ -30,8 +23,6 @@ else (LOUDMOUTH_INCLUDE_DIRS AND LOUDMOU
       ${_LOUDMOUTHLinkDir}
     )
 
-  endif(NOT WIN32)
-
   if (LOUDMOUTH_INCLUDE_DIRS AND LOUDMOUTH_LIBRARIES)
     SET(LOUDMOUTH_FOUND TRUE)
   else (LOUDMOUTH_INCLUDE_DIRS AND LOUDMOUTH_LIBRARIES)
