--- cmake/os/FreeBSD.cmake.orig	2018-10-04 05:48:22 UTC
+++ cmake/os/FreeBSD.cmake
@@ -37,8 +37,20 @@ IF(NOT FORCE_UNSUPPORTED_COMPILER)
     IF(NOT HAVE_SUPPORTED_CLANG_VERSION)
       MESSAGE(FATAL_ERROR "Clang 3.3 or newer is required!")
     ENDIF()
-  ELSE()
-    MESSAGE(FATAL_ERROR "Unsupported compiler!")
+    CHECK_C_SOURCE_RUNS("
+      int main()
+      {
+        return (__clang_major__ >= 4);
+      }" I386_ATOMIC_BUILTINS)
+    IF((CMAKE_SYSTEM_PROCESSOR MATCHES "i386") AND (NOT I386_ATOMIC_BUILTINS))
+      SET(HAVE_GCC_ATOMIC_BUILTINS CACHE  INTERNAL "")
+    ENDIF()
+  ELSEIF(CMAKE_COMPILER_IS_GNUCC)
+    EXECUTE_PROCESS(COMMAND ${CMAKE_C_COMPILER} -dumpversion
+                    OUTPUT_VARIABLE GCC_VERSION)
+    IF(GCC_VERSION VERSION_LESS 4.4)
+      MESSAGE(FATAL_ERROR "GCC 4.4 or newer is required!")
+    ENDIF()
   ENDIF()
 ENDIF()
 
