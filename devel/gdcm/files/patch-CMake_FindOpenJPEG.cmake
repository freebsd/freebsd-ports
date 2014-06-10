--- CMake/FindOpenJPEG.cmake.orig	2014-04-03 09:33:49.000000000 +0200
+++ CMake/FindOpenJPEG.cmake	2014-06-10 09:34:13.000000000 +0200
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
@@ -51,3 +59,4 @@
   OPENJPEG_INCLUDE_DIR
   )
 endif()
+endif()
