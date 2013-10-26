--- ./cmake/modules/FindLLVM.cmake.orig	2012-12-29 12:27:12.000000000 +0100
+++ ./cmake/modules/FindLLVM.cmake	2013-10-26 15:46:16.168023085 +0200
@@ -27,11 +27,13 @@
       set(LLVM_FOUND TRUE)
     endif(LLVM_INCLUDE_DIR AND LLVM_LIBS_DIR)
   else (MSVC)
-    find_program(LLVM_CONFIG_EXECUTABLE
+    if(NOT LLVM_CONFIG_EXECUTABLE)
+      find_program(LLVM_CONFIG_EXECUTABLE
         NAMES llvm-config
         PATHS
         /opt/local/bin
-    )
+      )
+    endif()
     
     exec_program(${LLVM_CONFIG_EXECUTABLE} ARGS --version OUTPUT_VARIABLE LLVM_VERSION )
     
