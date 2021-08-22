Work around upstream bug #1175 and make the build more robust
against minor platform differences.  -Werror should not be
provided in release builds.

--- cmake/modules/c_flags.cmake.orig	2021-04-24 22:24:02 UTC
+++ cmake/modules/c_flags.cmake
@@ -44,11 +44,3 @@ endif ()
 if (NOT (WIN32 OR (EXISTS "/etc/debian_version" AND MINGW)))
     add_cflag_if_supported("-fPIC")
 endif ()
-
-if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
-    add_cflag_if_supported("-ggdb")
-    add_cflag_if_supported("-O0")
-else ()
-    add_cflag_if_supported("-O2")
-    add_cflag_if_supported("-Werror")
-endif ()
