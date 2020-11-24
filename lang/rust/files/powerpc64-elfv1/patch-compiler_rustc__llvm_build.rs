--- compiler/rustc_llvm/build.rs.orig	2019-12-16 15:38:05 UTC
+++ compiler/rustc_llvm/build.rs
@@ -273,7 +273,14 @@ fn main() {
     };
 
     // C++ runtime library
-    if !target.contains("msvc") {
+    if target == "powerpc64-unknown-freebsd" {
+        if is_crossed {
+            println!("cargo:rustc-link-search=native=%WRKDIR%/usr/local/lib/%CC%");
+        } else {
+            println!("cargo:rustc-link-search=native=/usr/local/lib/%CC%");
+        }
+        println!("cargo:rustc-link-lib=static=stdc++");
+    } else if !target.contains("msvc") {
         if let Some(s) = llvm_static_stdcpp {
             assert!(!cxxflags.contains("stdlib=libc++"));
             let path = PathBuf::from(s);
