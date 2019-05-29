Avoid unnecessarily restarting the LLVM build and installing it
into STAGEDIR during the install phase.

https://github.com/rust-lang/rust/issues/61206

--- src/bootstrap/native.rs.orig	2019-05-22 05:39:52 UTC
+++ src/bootstrap/native.rs
@@ -92,17 +92,9 @@ impl Step for Llvm {
             .join(exe("llvm-config", &*builder.config.build));
         let done_stamp = out_dir.join("llvm-finished-building");
 
-        if let Some(llvm_commit) = llvm_info.sha() {
             if done_stamp.exists() {
-                let done_contents = t!(fs::read(&done_stamp));
-
-                // If LLVM was already built previously and the submodule's commit didn't change
-                // from the previous build, then no action is required.
-                if done_contents == llvm_commit.as_bytes() {
-                    return build_llvm_config
-                }
+                return build_llvm_config
             }
-        }
 
         let _folder = builder.fold_output(|| "llvm");
         let descriptor = if emscripten { "Emscripten " } else { "" };
@@ -218,6 +210,10 @@ impl Step for Llvm {
             }
         }
 
+        if target == "powerpc64-unknown-freebsd" {
+            cfg.define("CMAKE_EXE_LINKER_FLAGS", "-Wl,-rpath=/usr/local/lib/%CC% -L/usr/local/lib/%CC%");
+        }
+
         // http://llvm.org/docs/HowToCrossCompileLLVM.html
         if target != builder.config.build && !emscripten {
             builder.ensure(Llvm {
@@ -283,9 +279,7 @@ impl Step for Llvm {
 
         cfg.build();
 
-        if let Some(llvm_commit) = llvm_info.sha() {
-            t!(fs::write(&done_stamp, llvm_commit));
-        }
+        t!(fs::write(&done_stamp, "done building LLVM"));
 
         build_llvm_config
     }
