--- configure.cmake.orig	2018-01-16 23:26:09 UTC
+++ configure.cmake
@@ -43,6 +43,12 @@ IF(UNIX)
 ENDIF()
 
 
+IF(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+  SET(CMAKE_SHARED_LIBRARY_C_FLAGS
+    "${CMAKE_SHARED_LIBRARY_C_FLAGS} ${CMAKE_C_FLAGS} -L%%FREEBSD_LOCAL_LIB%%")
+ENDIF()
+
+
 IF(CMAKE_SYSTEM_NAME MATCHES "SunOS" AND CMAKE_COMPILER_IS_GNUCXX)
   ## We will be using gcc to generate .so files
   ## Add C flags (e.g. -m64) to CMAKE_SHARED_LIBRARY_C_FLAGS
