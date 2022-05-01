Revert part of [1] as it causes cross build problem with lang/rust-bootstrap@powerpc

[1] https://github.com/rust-lang/rust/commit/07dae5a97b64100f5abd511f1e2d5a6263a54006

--- src/bootstrap/native.rs.orig	2022-04-13 15:53:33.692586000 +0200
+++ src/bootstrap/native.rs	2022-04-13 15:53:47.191939000 +0200
@@ -318,7 +318,7 @@ impl Step for Llvm {
 
         // Workaround for ppc32 lld limitation
         if target == "powerpc-unknown-freebsd" {
-            ldflags.exe.push(" -fuse-ld=bfd");
+            cfg.define("CMAKE_EXE_LINKER_FLAGS", "-fuse-ld=bfd");
         }
 
         // https://llvm.org/docs/HowToCrossCompileLLVM.html
