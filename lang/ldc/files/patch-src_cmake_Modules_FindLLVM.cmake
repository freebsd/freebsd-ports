--- cmake/Modules/FindLLVM.cmake.orig	2017-05-04 11:46:42.432136000 -0700
+++ cmake/Modules/FindLLVM.cmake	2017-05-04 11:47:47.326728000 -0700
@@ -27,7 +27,9 @@
 # We also want an user-specified LLVM_ROOT_DIR to take precedence over the
 # system default locations such as /usr/local/bin. Executing find_program()
 # multiples times is the approach recommended in the docs.
-set(llvm_config_names llvm-config-3.9 llvm-config39
+set(llvm_config_names llvm-config-5.0 llvm-config50
+                      llvm-config-4.0 llvm-config40
+                      llvm-config-3.9 llvm-config39
                       llvm-config-3.8 llvm-config38
                       llvm-config-3.7 llvm-config37
                       llvm-config-3.6 llvm-config36
