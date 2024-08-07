--- src/LLVM_Runtime_Linker.cpp.orig	2024-07-17 16:16:39 UTC
+++ src/LLVM_Runtime_Linker.cpp
@@ -481,6 +481,9 @@ llvm::Triple get_triple_for_target(const Target &targe
         if (target.os == Target::Linux) {
             triple.setOS(llvm::Triple::Linux);
             triple.setEnvironment(llvm::Triple::GNU);
+	} else if (target.os == Target::FreeBSD) {
+            triple.setOS(llvm::Triple::FreeBSD);
+            triple.setEnvironment(llvm::Triple::GNU);
         } else if (target.os == Target::OSX) {
             triple.setVendor(llvm::Triple::Apple);
             triple.setOS(llvm::Triple::MacOSX);
@@ -527,6 +530,9 @@ llvm::Triple get_triple_for_target(const Target &targe
         } else if (target.os == Target::Linux) {
             triple.setOS(llvm::Triple::Linux);
             triple.setEnvironment(llvm::Triple::GNUEABIHF);
+        } else if (target.os == Target::FreeBSD) {
+            triple.setOS(llvm::Triple::FreeBSD);
+            triple.setEnvironment(llvm::Triple::GNUEABIHF);
         } else if (target.os == Target::Windows) {
             user_assert(target.bits == 64) << "Windows ARM targets must be 64-bit.\n";
             triple.setVendor(llvm::Triple::PC);
@@ -588,6 +594,8 @@ llvm::Triple get_triple_for_target(const Target &targe
 
         if (target.os == Target::Linux) {
             triple.setOS(llvm::Triple::Linux);
+	} else if (target.os == Target::FreeBSD) {
+            triple.setOS(llvm::Triple::FreeBSD);
         } else if (target.os == Target::Android) {
             triple.setOS(llvm::Triple::Linux);
             triple.setEnvironment(llvm::Triple::Android);
@@ -923,7 +931,7 @@ std::unique_ptr<llvm::Module> get_initial_module_for_t
     if (module_type != ModuleGPU) {
         if (module_type != ModuleJITInlined && module_type != ModuleAOTNoRuntime) {
             // OS-dependent modules
-            if (t.os == Target::Linux) {
+            if (t.os == Target::Linux || t.os == Target::FreeBSD) {
                 add_allocator();
                 modules.push_back(get_initmod_posix_allocator(c, bits_64, debug));
                 modules.push_back(get_initmod_posix_error_handler(c, bits_64, debug));
@@ -1113,7 +1121,7 @@ std::unique_ptr<llvm::Module> get_initial_module_for_t
             }
 
             // Prefer using fopen_lfs on Linux systems, which calls fopen64() to ensure LFS support.
-            if (t.os == Target::Linux) {
+            if (t.os == Target::Linux || t.os == Target::FreeBSD) {
                 modules.push_back(get_initmod_fopen_lfs(c, bits_64, debug));
             } else {
                 modules.push_back(get_initmod_fopen(c, bits_64, debug));
