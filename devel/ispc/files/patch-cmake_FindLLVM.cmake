- workaround for https://github.com/ispc/ispc/issues/2318

--- cmake/FindLLVM.cmake.orig	2022-05-05 23:06:57 UTC
+++ cmake/FindLLVM.cmake
@@ -33,7 +33,7 @@
 #
 # ispc FindLLVM.cmake
 #
-find_package(LLVM REQUIRED CONFIG)
+find_package(LLVM ${FREEBSD_LLVM_VERSION} REQUIRED CONFIG)
     if (NOT LLVM_FOUND )
         message(FATAL_ERROR "LLVM package can't be found. \
                 Set CMAKE_PREFIX_PATH variable to LLVM's installation prefix.")
@@ -41,8 +41,8 @@ find_package(LLVM REQUIRED CONFIG)
     set(LLVM_VERSION "LLVM_${LLVM_VERSION_MAJOR}_${LLVM_VERSION_MINOR}")
     message(STATUS "Found LLVM ${LLVM_VERSION}")
 
-find_program(LLVM_CONFIG_EXECUTABLE NAMES llvm-config
-    PATHS ${LLVM_TOOLS_BINARY_DIR} PATH_SUFFIXES bin NO_DEFAULT_PATH)
+find_program(LLVM_CONFIG_EXECUTABLE NAMES llvm-config${FREEBSD_LLVM_VERSION}
+    PATHS ${LLVM_TOOLS_BINARY_DIR} PATH_SUFFIXES bin)
     if (NOT LLVM_CONFIG_EXECUTABLE)
         message(FATAL_ERROR "Failed to find llvm-config")
     endif()
