--- CMake/FindLLVM.cmake.orig	2015-04-17 03:59:38.000000000 +0200
+++ CMake/FindLLVM.cmake	2015-05-09 00:27:01.012701000 +0200
@@ -52,21 +52,21 @@
 
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
