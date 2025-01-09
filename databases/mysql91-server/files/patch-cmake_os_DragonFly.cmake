--- cmake/os/DragonFly.cmake.orig	2016-04-14 10:16:17 UTC
+++ cmake/os/DragonFly.cmake
@@ -0,0 +1,24 @@
+INCLUDE(CheckCSourceRuns)
+
+# We require at least GCC 4.4 or Clang 3.3.
+IF(NOT FORCE_UNSUPPORTED_COMPILER)
+  IF(CMAKE_COMPILER_IS_GNUCC)
+    EXECUTE_PROCESS(COMMAND ${CMAKE_C_COMPILER} -dumpversion
+                    OUTPUT_VARIABLE GCC_VERSION)
+    IF(GCC_VERSION VERSION_LESS 4.4)
+      MESSAGE(FATAL_ERROR "GCC 4.4 or newer is required!")
+    ENDIF()
+  ELSEIF(CMAKE_C_COMPILER_ID MATCHES "Clang")
+    CHECK_C_SOURCE_RUNS("
+      int main()
+      {
+        return (__clang_major__ < 3) ||
+               (__clang_major__ == 3 && __clang_minor__ < 3);
+      }" HAVE_SUPPORTED_CLANG_VERSION)
+    IF(NOT HAVE_SUPPORTED_CLANG_VERSION)
+      MESSAGE(FATAL_ERROR "Clang 3.3 or newer is required!")
+    ENDIF()
+  ELSE()
+    MESSAGE(FATAL_ERROR "Unsupported compiler!")
+  ENDIF()
+ENDIF()
