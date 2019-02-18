--- src/librustc_llvm/build.rs.orig	2019-01-16 09:30:27 UTC
+++ src/librustc_llvm/build.rs
@@ -256,7 +256,10 @@ fn main() {
     };
 
     // C++ runtime library
-    if !target.contains("msvc") {
+    if target == "powerpc64-unknown-freebsd" {
+        println!("cargo:rustc-link-search=native=/usr/local/lib/%CC%");
+        println!("cargo:rustc-link-lib=static=stdc++");
+    } else if !target.contains("msvc") {
         if let Some(s) = llvm_static_stdcpp {
             assert!(!cxxflags.contains("stdlib=libc++"));
             let path = PathBuf::from(s);
