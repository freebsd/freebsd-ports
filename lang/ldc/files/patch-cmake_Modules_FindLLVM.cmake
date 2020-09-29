--- cmake/Modules/FindLLVM.cmake.orig	2020-07-15 20:25:23 UTC
+++ cmake/Modules/FindLLVM.cmake
@@ -30,7 +30,7 @@
 # We also want an user-specified LLVM_ROOT_DIR to take precedence over the
 # system default locations such as /usr/local/bin. Executing find_program()
 # multiples times is the approach recommended in the docs.
-set(llvm_config_names llvm-config-10.0 llvm-config100 llvm-config-10
+set(llvm_config_names llvm-config-10.0 llvm-config100 llvm-config-10 llvm-config10
                       llvm-config-9.0 llvm-config90 llvm-config-9
                       llvm-config-8.0 llvm-config80 llvm-config-8
                       llvm-config-7.0 llvm-config70 llvm-config-7
