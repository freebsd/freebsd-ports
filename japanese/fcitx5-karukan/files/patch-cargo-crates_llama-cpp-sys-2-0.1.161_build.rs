--- cargo-crates/llama-cpp-sys-2-0.1.161/build.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/llama-cpp-sys-2-0.1.161/build.rs
@@ -22,6 +22,7 @@ enum TargetOs {
     Windows(WindowsVariant),
     Apple(AppleVariant),
     Linux,
+    FreeBSD,
     Android,
     Emscripten,
 }
@@ -81,6 +82,8 @@ fn parse_target_os() -> Result<(TargetOs, String), Str
         Ok((TargetOs::Android, target))
     } else if target.contains("linux") {
         Ok((TargetOs::Linux, target))
+    } else if target.contains("freebsd") {
+        Ok((TargetOs::FreeBSD, target))
     } else if target.contains("emscripten") {
         Ok((TargetOs::Emscripten, target))
     } else {
@@ -124,7 +127,7 @@ fn lib_suffix(target_os: &TargetOs, shared: bool) -> &
                 ".a"
             }
         }
-        TargetOs::Linux | TargetOs::Android | TargetOs::Emscripten => {
+        TargetOs::Linux | TargetOs::FreeBSD | TargetOs::Android | TargetOs::Emscripten => {
             if shared {
                 ".so"
             } else {
@@ -1006,7 +1009,7 @@ fn main() {
         config.define("LLAMA_WASM_MEM64", mem64);
     }
 
-    if matches!(target_os, TargetOs::Linux)
+    if matches!(target_os, TargetOs::Linux | TargetOs::FreeBSD)
         && target_triple.contains("aarch64")
         && target_cpu != Some("native".into())
     {
@@ -1057,7 +1060,7 @@ fn main() {
                     config.cxxflag("/FS");
                 }
             }
-            TargetOs::Linux => {
+            TargetOs::Linux | TargetOs::FreeBSD => {
                 // If we are not using system provided vulkan SDK, add vulkan libs for linking
                 if let Ok(vulkan_path) = env::var("VULKAN_SDK") {
                     let vulkan_lib_path = Path::new(&vulkan_path).join("lib");
@@ -1511,6 +1514,14 @@ fn main() {
                 println!("cargo:rustc-link-lib=static=stdc++");
             } else {
                 println!("cargo:rustc-link-lib=dylib=stdc++");
+            }
+        }
+        TargetOs::FreeBSD => {
+            if cfg!(feature = "static-stdcxx") {
+                emit_compiler_static_archive_search_path("libc++.a");
+                println!("cargo:rustc-link-lib=static=c++");
+            } else {
+                println!("cargo:rustc-link-lib=dylib=c++");
             }
         }
         TargetOs::Apple(ref variant) => {
