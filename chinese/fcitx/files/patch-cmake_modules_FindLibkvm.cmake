diff --git a/cmake/FindLibkvm.cmake b/cmake/FindLibkvm.cmake
index a66b85d..4453fd4 100644
--- cmake/FindLibkvm.cmake
+++ cmake/FindLibkvm.cmake
@@ -5,23 +5,11 @@
 #  LIBKVM_INCLUDE_DIR - Libkvm include directory
 #  LIBKVM_LIBRARIES - Libraries needed to use Libkvm
 #
- 
-if(LIBKVM_INCLUDE_DIR AND LIBKVM_FOUND)
-  set(Libkvm_FIND_QUIETLY TRUE)
-endif(LIBKVM_INCLUDE_DIR AND LIBKVM_FOUND)
- 
+
 find_path(LIBKVM_INCLUDE_DIR kvm.h)
- 
-set(LIBKVM_FOUND FALSE)
- 
-if(LIBKVM_INCLUDE_DIR)
-    find_library(LIBKVM_LIBRARIES NAMES kvm)
-    if(LIBKVM_LIBRARIES)
-      set(LIBKVM_FOUND TRUE)
-    endif(LIBKVM_LIBRARIES)
-endif(LIBKVM_INCLUDE_DIR)
- 
+find_library(LIBKVM_LIBRARIES NAMES kvm)
+
 include(FindPackageHandleStandardArgs)
-find_package_handle_standard_args(Libkvm  DEFAULT_MSG  LIBKVM_INCLUDE_DIR  LIBKVM_FOUND)
- 
-mark_as_advanced(LIBKVM_INCLUDE_DIR  LIBKVM_LIBRARIES  LIBKVM_LIBC_HAS_KVM_OPEN  LIBKVM_FOUND)
+find_package_handle_standard_args(Libkvm  DEFAULT_MSG  LIBKVM_INCLUDE_DIR  LIBKVM_LIBRARIES)
+
+mark_as_advanced(LIBKVM_INCLUDE_DIR  LIBKVM_LIBRARIES)
