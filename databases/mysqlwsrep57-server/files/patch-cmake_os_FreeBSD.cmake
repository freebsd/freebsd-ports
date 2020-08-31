--- cmake/os/FreeBSD.cmake.orig	2018-10-04 05:48:22 UTC
+++ cmake/os/FreeBSD.cmake
@@ -30,6 +30,20 @@ IF(NOT FORCE_UNSUPPORTED_COMPILER)
     IF(NOT HAVE_SUPPORTED_CLANG_VERSION)
       MESSAGE(FATAL_ERROR "Clang 3.3 or newer is required!")
     ENDIF()
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
   ELSE()
     MESSAGE(FATAL_ERROR "Unsupported compiler!")
   ENDIF()
@@ -38,4 +52,6 @@ ENDIF()
 # Should not be needed any more, but kept for easy resurrection if needed
 #   #Legacy option, maybe not needed anymore , taken as is from autotools build
 #   ADD_DEFINITIONS(-DNET_RETRY_COUNT=1000000)
-
+# For GCC maybe it's also good idea to use
+#   ADD_DEFINITIONS(-D_GNU_SOURCE)
+    
