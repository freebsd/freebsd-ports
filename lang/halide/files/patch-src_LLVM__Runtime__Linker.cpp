--- src/LLVM_Runtime_Linker.cpp.orig	2024-02-20 17:13:06 UTC
+++ src/LLVM_Runtime_Linker.cpp
@@ -432,6 +432,9 @@ llvm::Triple get_triple_for_target(const Target &targe
         if (target.os == Target::Linux) {
             triple.setOS(llvm::Triple::Linux);
             triple.setEnvironment(llvm::Triple::GNU);
+	} else if (target.os == Target::Linux || target.os == Target::FreeBSD) {
+            triple.setOS(llvm::Triple::FreeBSD);
+            triple.setEnvironment(llvm::Triple::GNU);
         } else if (target.os == Target::OSX) {
             triple.setVendor(llvm::Triple::Apple);
             triple.setOS(llvm::Triple::MacOSX);
@@ -478,6 +481,9 @@ llvm::Triple get_triple_for_target(const Target &targe
         } else if (target.os == Target::Linux) {
             triple.setOS(llvm::Triple::Linux);
             triple.setEnvironment(llvm::Triple::GNUEABIHF);
+        } else if (target.os == Target::FreeBSD) {
+            triple.setOS(llvm::Triple::FreeBSD);
+            triple.setEnvironment(llvm::Triple::GNUEABIHF);
         } else if (target.os == Target::Windows) {
             user_assert(target.bits == 64) << "Windows ARM targets must be 64-bit.\n";
             triple.setVendor(llvm::Triple::PC);
@@ -539,6 +545,8 @@ llvm::Triple get_triple_for_target(const Target &targe
 
         if (target.os == Target::Linux) {
             triple.setOS(llvm::Triple::Linux);
+	} else if (target.os == Target::FreeBSD) {
+            triple.setOS(llvm::Triple::FreeBSD);
         } else if (target.os == Target::Android) {
             triple.setOS(llvm::Triple::Linux);
             triple.setEnvironment(llvm::Triple::Android);
@@ -855,7 +863,7 @@ std::unique_ptr<llvm::Module> get_initial_module_for_t
     if (module_type != ModuleGPU) {
         if (module_type != ModuleJITInlined && module_type != ModuleAOTNoRuntime) {
             // OS-dependent modules
-            if (t.os == Target::Linux) {
+            if (t.os == Target::Linux || t.os == Target::FreeBSD) {
                 add_allocator();
                 modules.push_back(get_initmod_posix_allocator(c, bits_64, debug));
                 modules.push_back(get_initmod_posix_error_handler(c, bits_64, debug));
@@ -1045,7 +1053,7 @@ std::unique_ptr<llvm::Module> get_initial_module_for_t
             }
 
             // Prefer using fopen_lfs on Linux systems, which calls fopen64() to ensure LFS support.
-            if (t.os == Target::Linux) {
+            if (t.os == Target::Linux || t.os == Target::FreeBSD) {
                 modules.push_back(get_initmod_fopen_lfs(c, bits_64, debug));
             } else {
                 modules.push_back(get_initmod_fopen(c, bits_64, debug));
@@ -1209,7 +1217,7 @@ std::unique_ptr<llvm::Module> get_initial_module_for_t
             if (t.os == Target::Android) {
                 // Only platform that supports OpenGL Compute for now.
                 modules.push_back(get_initmod_opengl_egl_context(c, bits_64, debug));
-            } else if (t.os == Target::Linux) {
+            } else if (t.os == Target::Linux || t.os == Target::FreeBSD) {
                 if (t.has_feature(Target::EGL)) {
                     modules.push_back(get_initmod_opengl_egl_context(c, bits_64, debug));
                 } else {
