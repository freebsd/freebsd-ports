--- cmake/os/FreeBSD.cmake.orig	2018-12-16 19:27:57 UTC
+++ cmake/os/FreeBSD.cmake
@@ -30,8 +30,6 @@ IF(NOT FORCE_UNSUPPORTED_COMPILER)
     IF(NOT HAVE_SUPPORTED_CLANG_VERSION)
       MESSAGE(FATAL_ERROR "Clang 3.3 or newer is required!")
     ENDIF()
-  ELSE()
-    MESSAGE(FATAL_ERROR "Unsupported compiler!")
   ENDIF()
 ENDIF()
 
