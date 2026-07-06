--- llvm-project/compiler-rt/cmake/config-ix.cmake.orig	2026-04-10 20:08:01 UTC
+++ llvm-project/compiler-rt/cmake/config-ix.cmake
@@ -247,6 +247,10 @@ test_targets()
 
 test_targets()
 
+if(COMPILER_RT_SUPPORTED_ARCH)
+  list(REMOVE_ITEM COMPILER_RT_SUPPORTED_ARCH i386)
+endif()
+
 # Returns a list of architecture specific target cflags in @out_var list.
 function(get_target_flags_for_arch arch out_var)
   list(FIND COMPILER_RT_SUPPORTED_ARCH ${arch} ARCH_INDEX)
