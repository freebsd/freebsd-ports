--- src/cmake/modules/FindLLVM.cmake.orig	2018-03-28 12:34:16 UTC
+++ src/cmake/modules/FindLLVM.cmake
@@ -94,11 +94,12 @@ if ((LLVM_LIBRARY OR LLVM_LIBRARIES OR L
     # if static LLVM libraries were requested, use llvm-config to generate
     # the list of what libraries we need, and substitute that in the right
     # way for LLVM_LIBRARY.
-    execute_process (COMMAND ${LLVM_CONFIG} --libfiles
+    execute_process (COMMAND ${LLVM_CONFIG} --libfiles --link-static
                      OUTPUT_VARIABLE LLVM_LIBRARIES
                      OUTPUT_STRIP_TRAILING_WHITESPACE)
     string (REPLACE " " ";" LLVM_LIBRARIES "${LLVM_LIBRARIES}")
     set (LLVM_LIBRARY "")
+    set(LLVM_SYSTEM_LIBRARIES "-lz -lexecinfo -lncurses")
   else ()
     set (LLVM_LIBRARIES "${LLVM_LIBRARY}")
   endif ()
