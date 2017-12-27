--- CMake/FindLLVM.cmake.orig	2017-01-20 10:40:51 UTC
+++ CMake/FindLLVM.cmake
@@ -46,21 +46,21 @@ endif (LLVM_FIND_VERSION_MAJOR AND LLVM_
 
 if (LLVM_INSTALL_DIR)
   find_program(CLANG_EXECUTABLE
-               NAMES clang-${LLVM_VERSION_NODOT} clang-${LLVM_VERSION_NOPATCH} clang
+               NAMES clang${LLVM_VERSION_NODOT} clang-${LLVM_VERSION_NODOT} clang-${LLVM_VERSION_NOPATCH} clang
                PATHS ${LLVM_INSTALL_DIR} NO_DEFAULT_PATH)
   find_program(LLVM_AS_EXECUTABLE
-               NAMES llvm-as-${LLVM_VERSION_NODOT} llvm-as-${LLVM_VERSION_NOPATCH} llvm-as
+               NAMES llvm-as${LLVM_VERSION_NODOT} llvm-as-${LLVM_VERSION_NODOT} llvm-as-${LLVM_VERSION_NOPATCH} llvm-as
                PATHS ${LLVM_INSTALL_DIR} NO_DEFAULT_PATH)
   find_program(LLVM_LINK_EXECUTABLE
-               NAMES llvm-link-${LLVM_VERSION_NODOT} llvm-link-${LLVM_VERSION_NOPATCH} llvm-link
+               NAMES llvm-link${LLVM_VERSION_NODOT} llvm-link-${LLVM_VERSION_NODOT} llvm-link-${LLVM_VERSION_NOPATCH} llvm-link
                PATHS ${LLVM_INSTALL_DIR} NO_DEFAULT_PATH)
 else (LLVM_INSTALL_DIR)
   find_program(CLANG_EXECUTABLE
-               NAMES clang-${LLVM_VERSION_NODOT} clang-${LLVM_VERSION_NOPATCH} clang)
+               NAMES clang${LLVM_VERSION_NODOT} clang-${LLVM_VERSION_NODOT} clang-${LLVM_VERSION_NOPATCH} clang)
   find_program(LLVM_AS_EXECUTABLE
-               NAMES llvm-as-${LLVM_VERSION_NODOT} llvm-as-${LLVM_VERSION_NOPATCH} llvm-as)
+               NAMES llvm-as${LLVM_VERSION_NODOT} llvm-as-${LLVM_VERSION_NODOT} llvm-as-${LLVM_VERSION_NOPATCH} llvm-as)
   find_program(LLVM_LINK_EXECUTABLE
-               NAMES llvm-link-${LLVM_VERSION_NODOT} llvm-link-${LLVM_VERSION_NOPATCH} llvm-link)
+               NAMES llvm-link${LLVM_VERSION_NODOT} llvm-link-${LLVM_VERSION_NODOT} llvm-link-${LLVM_VERSION_NOPATCH} llvm-link)
 endif (LLVM_INSTALL_DIR)
 
 execute_process(
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
