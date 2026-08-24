--- cargo-crates/llama-cpp-sys-2-0.1.154/build.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/llama-cpp-sys-2-0.1.154/build.rs
@@ -24,6 +24,7 @@ enum TargetOs {
     Apple(AppleVariant),
     Linux,
     Android,
+    FreeBSD,
 }
 
 macro_rules! debug_log {
@@ -83,6 +84,8 @@ fn parse_target_os() -> Result<(TargetOs, String), Str
         Ok((TargetOs::Android, target))
     } else if target.contains("linux") {
         Ok((TargetOs::Linux, target))
+    } else if target.contains("freebsd") {
+        Ok((TargetOs::FreeBSD, target))
     } else {
         Err(target)
     }
@@ -110,7 +113,7 @@ fn extract_lib_names(out_dir: &Path, build_shared_libs
                 "*.a"
             }
         }
-        TargetOs::Linux | TargetOs::Android => {
+        TargetOs::Linux | TargetOs::Android | TargetOs::FreeBSD => {
             if build_shared_libs {
                 "*.so"
             } else {
@@ -155,7 +158,7 @@ fn extract_lib_assets(out_dir: &Path, target_os: &Targ
     let shared_lib_pattern = match target_os {
         TargetOs::Windows(_) => "*.dll",
         TargetOs::Apple(_) => "*.dylib",
-        TargetOs::Linux | TargetOs::Android => "*.so",
+        TargetOs::Linux | TargetOs::Android | TargetOs::FreeBSD => "*.so",
     };
 
     let shared_libs_dir = match target_os {
@@ -194,7 +197,7 @@ fn library_file_exists(
                 (&["lib"], &["a"])
             }
         }
-        TargetOs::Linux | TargetOs::Android => {
+        TargetOs::Linux | TargetOs::Android | TargetOs::FreeBSD => {
             if build_shared_libs {
                 (&["lib"], &["so"])
             } else {
@@ -869,7 +872,7 @@ fn main() {
         println!("cargo:rustc-link-lib=android");
     }
 
-    if matches!(target_os, TargetOs::Linux)
+    if matches!(target_os, TargetOs::Linux | TargetOs::FreeBSD)
         && target_triple.contains("aarch64")
         && target_cpu != Some("native".into())
     {
@@ -905,7 +908,7 @@ fn main() {
                     config.cxxflag("/FS");
                 }
             }
-            TargetOs::Linux => {
+            TargetOs::Linux | TargetOs::FreeBSD => {
                 // If we are not using system provided vulkan SDK, add vulkan libs for linking
                 if let Ok(vulkan_path) = env::var("VULKAN_SDK") {
                     let vulkan_lib_path = Path::new(&vulkan_path).join("lib");
@@ -1363,6 +1366,14 @@ fn main() {
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
