Always look for libgpod using CMake instead of just using the pkg-config call
directly, as the latter does not use full paths.
--- cmake/modules/FindIpod.cmake
+++ cmake/modules/FindIpod.cmake
@@ -14,12 +14,6 @@ if (IPOD_INCLUDE_DIRS AND IPOD_LIBRARIES)
   SET(IPOD_FOUND TRUE)
 
 else (IPOD_INCLUDE_DIRS AND IPOD_LIBRARIES)
-  if(NOT WIN32)
-    # use pkg-config to get the directories and then use these values
-    # in the FIND_PATH() and FIND_LIBRARY() calls
-    find_package(PkgConfig)
-    PKG_SEARCH_MODULE(IPOD libgpod-1.0)
-  else(NOT WIN32)
     find_path(IPOD_INCLUDE_DIRS
     NAMES
     gpod/itdb.h
@@ -32,7 +26,7 @@ else (IPOD_INCLUDE_DIRS AND IPOD_LIBRARIES)
     if(IPOD_INCLUDE_DIRS AND IPOD_LIBRARIES)
        set(IPOD_FOUND ON)
     endif(IPOD_INCLUDE_DIRS AND IPOD_LIBRARIES)
-  endif(NOT WIN32)
+
   IF (IPOD_FOUND)
      IF (NOT IPOD_FIND_QUIETLY)
         MESSAGE(STATUS "Found libgpod-1 ${IPOD_VERSION}")
