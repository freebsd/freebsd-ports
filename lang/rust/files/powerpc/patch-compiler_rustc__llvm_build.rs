--- compiler/rustc_llvm/build.rs.orig	2022-11-15 08:26:08.366900000 +0100
+++ compiler/rustc_llvm/build.rs	2022-11-15 08:29:07.101616000 +0100
@@ -235,20 +235,18 @@ fn main() {
     let mut cmd = Command::new(&llvm_config);
     cmd.arg(llvm_link_arg).arg("--libs");
 
-    if !is_crossed {
+    if target.starts_with("arm")
+        || target.starts_with("powerpc-")
+    {
+        println!("cargo:rustc-link-lib=atomic");
+        println!("cargo:rustc-link-lib=z");
+    } else if !is_crossed {
         cmd.arg("--system-libs");
     } else if target.contains("windows-gnu") {
         println!("cargo:rustc-link-lib=shell32");
         println!("cargo:rustc-link-lib=uuid");
     } else if target.contains("netbsd") || target.contains("haiku") || target.contains("darwin") {
         println!("cargo:rustc-link-lib=z");
-    } else if target.starts_with("arm")
-        || target.starts_with("mips-")
-        || target.starts_with("mipsel-")
-        || target.starts_with("powerpc-")
-    {
-        // 32-bit targets need to link libatomic.
-        println!("cargo:rustc-link-lib=atomic");
     }
     cmd.args(&components);
 
