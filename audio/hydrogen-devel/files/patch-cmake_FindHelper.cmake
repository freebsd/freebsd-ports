--- cmake/FindHelper.cmake.orig	2015-08-31 19:04:48 UTC
+++ cmake/FindHelper.cmake
@@ -23,7 +23,7 @@ macro(FIND_HELPER prefix pkg_name header
             FIND_PACKAGE(PkgConfig)
         endif()
         if(PKG_CONFIG_FOUND)
-            pkg_check_modules(${prefix} ${pkg_name})
+            pkg_check_modules(PC_${prefix} ${pkg_name})
             #MESSAGE(STATUS  " LDFLAGS       ${${prefix}_LDFLAGS}" )
             #MESSAGE(STATUS  " CFLAGS        ${${prefix}_CFLAGS}" )
             #MESSAGE(STATUS  " INCLUDEDIRS   ${${prefix}_INCLUDE_DIRS}" )
@@ -36,12 +36,14 @@ macro(FIND_HELPER prefix pkg_name header
 
         find_path(${prefix}_INCLUDE_DIR
             NAMES ${header}
-            PATHS ${${prefix}_INCLUDE_DIRS} ${${prefix}_INCLUDEDIR} ${${prefix}_INCLUDE_PATHS} ENV ${prefix}_INCLUDE
+            HINTS ${PC_${prefix}_INCLUDE_DIRS} ${PC_${prefix}_INCLUDEDIR} ${PC_${prefix}_INCLUDE_PATHS}
+            ENV ${prefix}_INCLUDE
         )
 
         find_library(${prefix}_LIBRARIES
             NAMES ${lib}
-            PATHS ${${prefix}_LIBDIR} ${${prefix}_LIBRARY_DIRS} ${${prefix}_LIB_PATHS} ENV ${prefix}_PATH
+            HINTS ${PC_${prefix}_LIBDIR} ${PC_${prefix}_LIBRARY_DIRS} ${PC_${prefix}_LIB_PATHS}
+            ENV ${prefix}_PATH
         )
     endif()
 
