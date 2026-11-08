--- swift/utils/swift_build_support/swift_build_support/products/llvm.py.orig	2026-09-13 22:35:30 UTC
+++ swift/utils/swift_build_support/swift_build_support/products/llvm.py
@@ -247,7 +247,9 @@ class LLVM(cmake_product.CMakeProduct):
                 crosscompiling=self.is_cross_compile_target(host_target))
             llvm_cmake_options.define('CMAKE_TOOLCHAIN_FILE:PATH', toolchain_file)
 
-        target_supports_split_dwarf = host_target.startswith(('linux', 'freebsd'))
+        # FIXME: -gsplit-dwar breaks object caching using ccache 3.7 on FreeBSD
+        # target_supports_split_dwarf = host_target.startswith(('linux', 'freebsd'))
+        target_supports_split_dwarf = host_target.startswith(('linux'))
         if target_supports_split_dwarf and self.is_debug_info():
             # On platforms that support split-dwarf, build LLVM and subprojects with
             #  -gsplit-dwarf which is more space/time efficient than -g on that platform.
