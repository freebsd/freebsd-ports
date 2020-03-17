--- src/bootstrap/native.rs.orig	2019-11-04 15:45:21 UTC
+++ src/bootstrap/native.rs
@@ -241,6 +241,10 @@ impl Step for Llvm {
             }
         }
 
+        if target == "powerpc64-unknown-freebsd" {
+            cfg.define("CMAKE_EXE_LINKER_FLAGS", "-Wl,-rpath=/usr/local/lib/%CC% -L/usr/local/lib/%CC%");
+        }
+
         // http://llvm.org/docs/HowToCrossCompileLLVM.html
         if target != builder.config.build && !emscripten {
             builder.ensure(Llvm {
