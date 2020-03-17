--- src/librustc_llvm/build.rs.orig	2020-03-09 22:11:17 UTC
+++ src/librustc_llvm/build.rs
@@ -264,7 +264,10 @@ fn main() {
     };
 
     // C++ runtime library
-    if !target.contains("msvc") {
+    if target == "powerpc64-unknown-freebsd" && !is_crossed {
+        println!("cargo:rustc-link-search=native=/usr/local/lib/%CC%");
+        println!("cargo:rustc-link-lib=static=stdc++");
+    } else if !target.contains("msvc") {
         if let Some(s) = llvm_static_stdcpp {
             assert!(!cxxflags.contains("stdlib=libc++"));
             let path = PathBuf::from(s);
