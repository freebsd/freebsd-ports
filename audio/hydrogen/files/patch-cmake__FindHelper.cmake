Sent upstream: https://github.com/hydrogen-music/hydrogen/pull/290

cmake: Call find_path and find_library even if pkg-config calls work.

Instead of calling pkg_check_modules() with the same prefix as the calls
to find_library() and find_path(), pass PC_${prefix} to the former.

This way, we are able to use the paths that might have been found by
pkg-config as hints to the find_library and find_path calls. Doing so
helps systems where the dependent libraries (libarchive, libsndfile etc)
are not in the default linker path, as the linker is now called with the
libraries' absolute path:

c++ file1.o file2.o [...] -o hydrogen /usr/lib/libsndfile.so ...

instead of

c++ file1.o file2.o [...] -o hydrogen -lsndfile ...

as the latter requires one to manually pass "-L/usr/local/lib" to CMake
when configuring Hydrogen.

While here, use HINTS instead of PATHS when calling the find_*()
functions, as CMake's documentation says that "paths computed by system
introspection" should use HINTS, not PATHS, which is for hardcoded
paths.
--- cmake/FindHelper.cmake.orig	2014-09-09 18:39:33 UTC
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
 
