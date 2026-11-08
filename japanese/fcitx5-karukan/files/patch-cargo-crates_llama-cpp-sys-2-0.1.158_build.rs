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
@@ -687,11 +690,12 @@ fn main() {
         // rust code isn't using `target-cpu=native`, so llama.cpp shouldn't use GGML_NATIVE either
         config.define("GGML_NATIVE", "OFF");
 
-        // if `target-cpu` is set set, also set -march for llama.cpp to the same value
+        // if `target-cpu` is set, also set -march/-mcpu for llama.cpp to the same value
         if let Some(ref cpu) = target_cpu {
-            debug_log!("Setting baseline architecture: -march={}", cpu);
-            config.cflag(format!("-march={}", cpu));
-            config.cxxflag(format!("-march={}", cpu));
+            let flag = if target_triple.starts_with("powerpc") { "-mcpu" } else { "-march" };
+            debug_log!("Setting baseline architecture: {}={}", flag, cpu);
+            config.cflag(format!("{}={}", flag, cpu));
+            config.cxxflag(format!("{}={}", flag, cpu));
         }
 
         // cargo only sets this when at least one target feature is enabled, which
@@ -850,7 +854,7 @@ fn main() {
         println!("cargo:rustc-link-lib=android");
     }
 
-    if matches!(target_os, TargetOs::Linux)
+    if matches!(target_os, TargetOs::Linux | TargetOs::FreeBSD)
         && target_triple.contains("aarch64")
         && target_cpu != Some("native".into())
     {
@@ -901,7 +905,7 @@ fn main() {
                     config.cxxflag("/FS");
                 }
             }
-            TargetOs::Linux => {
+            TargetOs::Linux | TargetOs::FreeBSD => {
                 // If we are not using system provided vulkan SDK, add vulkan libs for linking
                 if let Ok(vulkan_path) = env::var("VULKAN_SDK") {
                     let vulkan_lib_path = Path::new(&vulkan_path).join("lib");
@@ -1346,6 +1350,14 @@ fn main() {
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
