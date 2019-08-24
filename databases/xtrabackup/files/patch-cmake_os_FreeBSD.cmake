--- cmake/os/FreeBSD.cmake.orig	2019-07-19 15:13:48 UTC
+++ cmake/os/FreeBSD.cmake
@@ -30,6 +30,12 @@ IF(NOT FORCE_UNSUPPORTED_COMPILER)
     IF(NOT HAVE_SUPPORTED_CLANG_VERSION)
       MESSAGE(FATAL_ERROR "Clang 3.3 or newer is required!")
     ENDIF()
+  ELSEIF(CMAKE_COMPILER_IS_GNUCC)
+    EXECUTE_PROCESS(COMMAND ${CMAKE_C_COMPILER} -dumpversion
+                    OUTPUT_VARIABLE GCC_VERSION)
+    IF(GCC_VERSION VERSION_LESS 4.4)
+      MESSAGE(FATAL_ERROR "GCC 4.4 or newer is required!")
+    ENDIF()
   ELSE()
     MESSAGE(FATAL_ERROR "Unsupported compiler!")
   ENDIF()
