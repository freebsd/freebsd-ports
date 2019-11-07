--- src/librustc_llvm/build.rs.orig	2019-11-04 15:45:21 UTC
+++ src/librustc_llvm/build.rs
@@ -273,7 +273,10 @@ fn main() {
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
