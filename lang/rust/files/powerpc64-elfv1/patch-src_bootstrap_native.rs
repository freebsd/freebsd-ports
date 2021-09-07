--- src/bootstrap/native.rs.orig	2021-09-06 18:42:35 UTC
+++ src/bootstrap/native.rs
@@ -277,6 +277,10 @@ impl Step for Llvm {
             }
         }
 
+        if target == "powerpc64-unknown-freebsd" {
+            cfg.define("CMAKE_EXE_LINKER_FLAGS", "-Wl,-rpath=/usr/local/lib/%CC% -L/usr/local/lib/%CC%");
+        }
+
         // https://llvm.org/docs/HowToCrossCompileLLVM.html
         if target != builder.config.build {
             builder.ensure(Llvm { target: builder.config.build });
