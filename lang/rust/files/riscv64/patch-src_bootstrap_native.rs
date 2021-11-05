--- src/bootstrap/native.rs.orig	2021-11-29 19:27:11 UTC
+++ src/bootstrap/native.rs
@@ -248,9 +248,14 @@ impl Step for Llvm {
             }
         }
 
-        if target.starts_with("riscv") {
-            // In RISC-V, using C++ atomics require linking to `libatomic` but the LLVM build
-            // system check cannot detect this. Therefore it is set manually here.
+        if !target.contains("freebsd") && target.starts_with("riscv") {
+            // RISC-V GCC erroneously requires linking against
+            // `libatomic` when using 1-byte and 2-byte C++
+            // atomics but the LLVM build system check cannot
+            // detect this. Therefore it is set manually here.
+            // FreeBSD uses Clang as its system compiler and
+            // provides no libatomic in its base system so does
+            // not want this.
             if !builder.config.llvm_tools_enabled {
                 cfg.define("CMAKE_EXE_LINKER_FLAGS", "-latomic");
             } else {
