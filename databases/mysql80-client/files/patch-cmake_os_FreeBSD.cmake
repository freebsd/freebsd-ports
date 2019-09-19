--- cmake/os/FreeBSD.cmake.orig	2019-06-25 10:23:30 UTC
+++ cmake/os/FreeBSD.cmake
@@ -45,8 +45,20 @@ IF(NOT FORCE_UNSUPPORTED_COMPILER)
       MESSAGE(FATAL_ERROR
         "GCC 5.3 or newer is required (-dumpversion says ${GCC_VERSION})")
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

