--- CMake/FindLLVM.cmake.orig	2017-01-20 10:40:51 UTC
+++ CMake/FindLLVM.cmake
@@ -100,6 +100,9 @@ execute_process(
   OUTPUT_STRIP_TRAILING_WHITESPACE
 )
 if (LLVM_SYSTEM_LIBS_ORIG)
+# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223191#c3
+string(REPLACE "-l/usr/lib/libexecinfo.so" "-lexecinfo"
+       LLVM_SYSTEM_LIBS_ORIG ${LLVM_SYSTEM_LIBS_ORIG})
 string(REGEX REPLACE " *\n" "" LLVM_SYSTEM_LIBS ${LLVM_SYSTEM_LIBS_ORIG})
 endif (LLVM_SYSTEM_LIBS_ORIG)
 endif (LLVM_VERSION_NODOT VERSION_GREATER 34)
