From 934145eb7023047e1add14f8bdad8e62a7c08d00 Mon Sep 17 00:00:00 2001
From: alexey semenyuk <alexsemenyuk88@gmail.com>
Date: Mon, 2 May 2022 19:24:50 +0000
Subject: [PATCH] Enables option split-debuginfo on all platforms

https://github.com/rust-lang/rust/pull/96648

--- src/bootstrap/builder.rs.orig	2022-05-01 20:28:31 UTC
+++ src/bootstrap/builder.rs
@@ -1406,9 +1406,7 @@ impl<'a> Builder<'a> {
         // FIXME(davidtwco): #[cfg(not(bootstrap))] - #95612 needs to be in the bootstrap compiler
         // for this conditional to be removed.
         if !target.contains("windows") || compiler.stage >= 1 {
-            if target.contains("linux") || target.contains("windows") {
-                rustflags.arg("-Zunstable-options");
-            }
+            rustflags.arg("-Zunstable-options");
             match self.config.rust_split_debuginfo {
                 SplitDebuginfo::Packed => rustflags.arg("-Csplit-debuginfo=packed"),
                 SplitDebuginfo::Unpacked => rustflags.arg("-Csplit-debuginfo=unpacked"),
