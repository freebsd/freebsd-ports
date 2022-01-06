Fix build with clang >= 12 or gcc >= 11

Backport from upstream, commit c4a42feb5333488360617a9b58f90e479659b744

--- cmake/compilers/Clang.cmake.orig	2021-10-04 09:50:18 UTC
+++ cmake/compilers/Clang.cmake
@@ -44,7 +44,7 @@ if (NOT TBB_STRICT AND COMMAND tbb_remove_compile_flag
 endif()
 
 # Enable Intel(R) Transactional Synchronization Extensions (-mrtm) and WAITPKG instructions support (-mwaitpkg) on relevant processors
-if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86|AMD64)")
+if (CMAKE_SYSTEM_PROCESSOR MATCHES "(AMD64|amd64|i.86|x86)")
     set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} -mrtm $<$<NOT:$<VERSION_LESS:${CMAKE_CXX_COMPILER_VERSION},12.0>>:-mwaitpkg>)
 endif()
 
--- cmake/compilers/GNU.cmake.orig	2021-10-04 09:50:18 UTC
+++ cmake/compilers/GNU.cmake
@@ -36,7 +36,7 @@ if (NOT CMAKE_GENERATOR MATCHES "Ninja" AND NOT CMAKE_
 endif()
 
 # Enable Intel(R) Transactional Synchronization Extensions (-mrtm) and WAITPKG instructions support (-mwaitpkg) on relevant processors
-if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86|AMD64)")
+if (CMAKE_SYSTEM_PROCESSOR MATCHES "(AMD64|amd64|i.86|x86)")
     set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} -mrtm $<$<AND:$<NOT:$<CXX_COMPILER_ID:Intel>>,$<NOT:$<VERSION_LESS:${CMAKE_CXX_COMPILER_VERSION},11.0>>>:-mwaitpkg>)
 endif()
 
