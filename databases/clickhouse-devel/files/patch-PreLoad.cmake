--- PreLoad.cmake.orig	2024-09-26 19:15:26 UTC
+++ PreLoad.cmake
@@ -15,12 +15,24 @@ endif()
     endif ()
 endif()
 
+# Default toolchain - this is needed to avoid dependency on OS files.
+execute_process(COMMAND uname -s
+    OUTPUT_VARIABLE OS
+    COMMAND_ERROR_IS_FATAL ANY
+)
+execute_process(COMMAND uname -m
+    OUTPUT_VARIABLE ARCH
+    COMMAND_ERROR_IS_FATAL ANY
+)
+
+
 # Check if environment is polluted.
-if (NOT "$ENV{CFLAGS}" STREQUAL ""
+if ((OS MATCHES "Linux") AND (NOT "$ENV{CFLAGS}" STREQUAL ""
     OR NOT "$ENV{CXXFLAGS}" STREQUAL ""
     OR NOT "$ENV{LDFLAGS}" STREQUAL ""
     OR CMAKE_C_FLAGS OR CMAKE_CXX_FLAGS OR CMAKE_EXE_LINKER_FLAGS OR CMAKE_MODULE_LINKER_FLAGS
-    OR CMAKE_C_FLAGS_INIT OR CMAKE_CXX_FLAGS_INIT OR CMAKE_EXE_LINKER_FLAGS_INIT OR CMAKE_MODULE_LINKER_FLAGS_INIT)
+    OR CMAKE_C_FLAGS_INIT OR CMAKE_CXX_FLAGS_INIT
+    OR CMAKE_EXE_LINKER_FLAGS_INIT OR CMAKE_MODULE_LINKER_FLAGS_INIT))
 
     # if $ENV
     message("CFLAGS: $ENV{CFLAGS}")
@@ -49,16 +61,6 @@ endif()
 
         Note: if you don't like this behavior, you can manually edit the cmake files, but please don't complain to developers.")
 endif()
-
-# Default toolchain - this is needed to avoid dependency on OS files.
-execute_process(COMMAND uname -s
-    OUTPUT_VARIABLE OS
-    COMMAND_ERROR_IS_FATAL ANY
-)
-execute_process(COMMAND uname -m
-    OUTPUT_VARIABLE ARCH
-    COMMAND_ERROR_IS_FATAL ANY
-)
 
 # By default, prefer clang on Linux
 # But note, that you still may change the compiler with -DCMAKE_C_COMPILER/-DCMAKE_CXX_COMPILER.
