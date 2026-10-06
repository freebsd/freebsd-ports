--- cargo-crates/llama-cpp-sys-2-0.1.158/build.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/llama-cpp-sys-2-0.1.158/build.rs
@@ -23,6 +23,7 @@ enum TargetOs {
     Apple(AppleVariant),
     Linux,
     Android,
+    FreeBSD,
 }
 
 macro_rules! debug_log {
@@ -80,6 +81,8 @@ fn parse_target_os() -> Result<(TargetOs, String), Str
         Ok((TargetOs::Android, target))
     } else if target.contains("linux") {
         Ok((TargetOs::Linux, target))
+    } else if target.contains("freebsd") {
+        Ok((TargetOs::FreeBSD, target))
     } else {
         Err(target)
     }
@@ -121,7 +124,7 @@ fn lib_suffix(target_os: &TargetOs, shared: bool) -> &
                 ".a"
             }
         }
-        TargetOs::Linux | TargetOs::Android => {
+        TargetOs::Linux | TargetOs::Android | TargetOs::FreeBSD => {
             if shared {
                 ".so"
             } else {
@@ -850,7 +853,7 @@ fn main() {
         println!("cargo:rustc-link-lib=android");
     }
 
-    if matches!(target_os, TargetOs::Linux)
+    if matches!(target_os, TargetOs::Linux | TargetOs::FreeBSD)
         && target_triple.contains("aarch64")
         && target_cpu != Some("native".into())
     {
@@ -901,7 +904,7 @@ fn main() {
                     config.cxxflag("/FS");
                 }
             }
-            TargetOs::Linux => {
+            TargetOs::Linux | TargetOs::FreeBSD => {
                 // If we are not using system provided vulkan SDK, add vulkan libs for linking
                 if let Ok(vulkan_path) = env::var("VULKAN_SDK") {
                     let vulkan_lib_path = Path::new(&vulkan_path).join("lib");
@@ -1346,6 +1349,14 @@ fn main() {
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
