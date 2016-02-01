--- CMake/FindOpenJPEG.cmake.orig	2015-08-22 14:09:50 UTC
+++ CMake/FindOpenJPEG.cmake
@@ -18,7 +18,15 @@
 # (To distribute this file outside of CMake, substitute the full
 #  License text for the above reference.)
 
-# Try first to locate a cmake config file
+# Try with pkg-config first
+find_package(PkgConfig)
+pkg_check_modules(OPENJPEG libopenjpeg1)
+if(OPENJPEG_FOUND)
+    set(OPENJPEG_MAJOR_VERSION 1)
+    set(OPENJPEG_INCLUDE_DIR ${OPENJPEG_INCLUDE_DIRS})
+    set(OPENJPEG_LIBRARIES ${OPENJPEG_LDFLAGS})
+else()
+# Try to locate a cmake config file
 find_package(OpenJPEG QUIET NO_MODULE)
 
 if( NOT OpenJPEG_DIR )
@@ -51,3 +59,4 @@ mark_as_advanced(
   OPENJPEG_INCLUDE_DIR
   )
 endif()
+endif()
