--- cmake/Config.cmake.orig	2016-11-03 06:50:51 UTC
+++ cmake/Config.cmake
@@ -27,7 +27,7 @@ elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Li
         # don't use the OpenGL ES implementation on Linux
         set(OPENGL_ES 0)
     endif()
-elseif(CMAKE_SYSTEM_NAME MATCHES "^k?FreeBSD$")
+elseif(CMAKE_SYSTEM_NAME MATCHES "^k?FreeBSD$" OR CMAKE_SYSTEM_NAME MATCHES "DragonFly")
     set(SFML_OS_FREEBSD 1)
     # don't use the OpenGL ES implementation on FreeBSD
     set(OPENGL_ES 0)
