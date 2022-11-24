From cbeec86a5594ef6ca36d0ea24b4cb7e3dbaded87 Mon Sep 17 00:00:00 2001
From: pkubaj <pkubaj@FreeBSD.org>
Date: Fri, 18 Nov 2022 12:36:49 +0000
Subject: [PATCH] Fix build on powerpc-unknown-freebsd

Probably also fixes build on arm and mips*. Related to https://github.com/rust-lang/rust/issues/104220
---
 compiler/rustc_llvm/build.rs | 15 +++++++++------
 1 file changed, 9 insertions(+), 6 deletions(-)

diff --git a/compiler/rustc_llvm/build.rs b/compiler/rustc_llvm/build.rs
index d35e4191cc0b1..afdf9ac8883e9 100644
--- compiler/rustc_llvm/build.rs
+++ compiler/rustc_llvm/build.rs
@@ -237,18 +237,21 @@ fn main() {
 
     if !is_crossed {
         cmd.arg("--system-libs");
-    } else if target.contains("windows-gnu") {
-        println!("cargo:rustc-link-lib=shell32");
-        println!("cargo:rustc-link-lib=uuid");
-    } else if target.contains("netbsd") || target.contains("haiku") || target.contains("darwin") {
-        println!("cargo:rustc-link-lib=z");
-    } else if target.starts_with("arm")
+    }
+
+    if target.starts_with("arm")
         || target.starts_with("mips-")
         || target.starts_with("mipsel-")
         || target.starts_with("powerpc-")
     {
         // 32-bit targets need to link libatomic.
         println!("cargo:rustc-link-lib=atomic");
+        println!("cargo:rustc-link-lib=z");
+    } else if target.contains("windows-gnu") {
+        println!("cargo:rustc-link-lib=shell32");
+        println!("cargo:rustc-link-lib=uuid");
+    } else if target.contains("netbsd") || target.contains("haiku") || target.contains("darwin") {
+        println!("cargo:rustc-link-lib=z");
     }
     cmd.args(&components);
 
