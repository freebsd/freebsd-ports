--- cmake/FindCDParanoia.cmake.orig	2024-05-30 23:46:53 UTC
+++ cmake/FindCDParanoia.cmake
@@ -43,10 +43,13 @@ The following cache variables may also be set:
   The directory containing ``cdda_interface.h``.
 #]===]
 
+include(CheckCSourceCompiles)
+
 # First use PKG-Config as a starting point.
 find_package(PkgConfig)
 if(PKG_CONFIG_FOUND)
-  pkg_check_modules(PC_CDParanoia QUIET cdparanoia)
+  pkg_check_modules(PC_CDParanoia QUIET libcdio_paranoia)
+  pkg_check_modules(PC_CDDA QUIET libcdio_cdda)
 endif(PKG_CONFIG_FOUND)
 
 find_path(CDParanoia_PARANOIA_INCLUDE_DIR
@@ -56,7 +59,7 @@ find_path(CDParanoia_INTERFACE_INCLUDE_DIR
 )
 find_path(CDParanoia_INTERFACE_INCLUDE_DIR
         NAMES cdda_interface.h
-        PATHS ${PC_CDParanoia_INCLUDE_DIRS}
+        PATHS ${PC_CDDA_INCLUDE_DIRS}
         PATH_SUFFIXES cdda
 )
 
@@ -66,7 +69,7 @@ find_library(CDParanoia_INTERFACE_LIBRARY
 )
 find_library(CDParanoia_INTERFACE_LIBRARY
         NAMES cdda_interface
-        PATHS ${PC_CDParanoia_LIBRARY_DIRS}
+        PATHS ${PC_CDDA_LIBRARY_DIRS}
 )
 
 # Set version from PC if applicable.
@@ -96,6 +99,7 @@ if(CDParanoia_FOUND)
     )
   endif ()
   if(NOT TARGET CDDA::Interface)
+    add_library(CDDA::Interface UNKNOWN IMPORTED)
     set_target_properties(CDDA::Interface PROPERTIES
             IMPORTED_LOCATION "${CDParanoia_INTERFACE_LIBRARY}"
             INTERFACE_COMPILE_OPTIONS "${PC_CDParanoia_CFLAGS_OTHER}"
@@ -118,4 +122,4 @@ mark_as_advanced(
         CDParanoia_INTERFACE_INCLUDE_DIR
         CDParanoia_PARANOIA_LIBRARY
         CDParanoia_INTERFACE_LIBRARY
-)
\ No newline at end of file
+)
