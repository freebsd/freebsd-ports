--- src/LLVM_Runtime_Linker.cpp.orig	2022-08-17 05:20:15 UTC
+++ src/LLVM_Runtime_Linker.cpp
@@ -833,7 +833,7 @@ std::unique_ptr<llvm::Module> get_initial_module_for_t
     if (module_type != ModuleGPU) {
         if (module_type != ModuleJITInlined && module_type != ModuleAOTNoRuntime) {
             // OS-dependent modules
-            if (t.os == Target::Linux) {
+            if (t.os == Target::Linux || t.os == Target::FreeBSD) {
                 modules.push_back(get_initmod_posix_allocator(c, bits_64, debug));
                 modules.push_back(get_initmod_posix_error_handler(c, bits_64, debug));
                 modules.push_back(get_initmod_posix_print(c, bits_64, debug));
