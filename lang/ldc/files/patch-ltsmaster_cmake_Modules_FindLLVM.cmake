--- ltsmaster/cmake/Modules/FindLLVM.cmake.orig	2020-07-13 18:03:33 UTC
+++ ltsmaster/cmake/Modules/FindLLVM.cmake
@@ -27,7 +27,8 @@
 # We also want an user-specified LLVM_ROOT_DIR to take precedence over the
 # system default locations such as /usr/local/bin. Executing find_program()
 # multiples times is the approach recommended in the docs.
-set(llvm_config_names llvm-config-6.0 llvm-config60
+set(llvm_config_names llvm-config-7.0 llvm-config70
+                      llvm-config-6.0 llvm-config60
                       llvm-config-5.0 llvm-config50
                       llvm-config-4.0 llvm-config40
                       llvm-config-3.9 llvm-config39
