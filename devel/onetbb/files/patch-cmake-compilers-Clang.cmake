Fix amd64 build for 13-STABLE and 14-CURRENT (clang >= 12.0.1)

--- cmake/compilers/Clang.cmake.orig	2021-10-04 09:50:18 UTC
+++ cmake/compilers/Clang.cmake
@@ -44,7 +44,7 @@ if (NOT TBB_STRICT AND COMMAND tbb_remove_compile_flag
 endif()
 
 # Enable Intel(R) Transactional Synchronization Extensions (-mrtm) and WAITPKG instructions support (-mwaitpkg) on relevant processors
-if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86|AMD64)")
+if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86|AMD64|amd64)")
     set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} -mrtm $<$<NOT:$<VERSION_LESS:${CMAKE_CXX_COMPILER_VERSION},12.0>>:-mwaitpkg>)
 endif()
 
