From 9741fbd202b2b55de95abe1eb7f3d8185e312444 Mon Sep 17 00:00:00 2001
From: Jake Goulding <jake.goulding@gmail.com>
Date: Sat, 11 Jul 2020 09:38:01 -0400
Subject: [PATCH] Don't allow `DESTDIR` to influence LLVM builds

When running a command like `DESTDIR=foo x.py install` in a completely
clean build directory, this will cause LLVM to be installed into
`DESTDIR`, which then causes the build to fail later when it attempts
to *use* those LLVM files.
---
 src/bootstrap/native.rs | 5 +++++
 1 file changed, 5 insertions(+)

--- src/bootstrap/native.rs.orig	2020-08-24 15:00:49 UTC
+++ src/bootstrap/native.rs
@@ -517,26 +522,9 @@ impl Step for Lld {
         let mut cfg = cmake::Config::new(builder.src.join("src/llvm-project/lld"));
         configure_cmake(builder, target, &mut cfg, true);
 
-        // This is an awful, awful hack. Discovered when we migrated to using
-        // clang-cl to compile LLVM/LLD it turns out that LLD, when built out of
-        // tree, will execute `llvm-config --cmakedir` and then tell CMake about
-        // that directory for later processing. Unfortunately if this path has
-        // forward slashes in it (which it basically always does on Windows)
-        // then CMake will hit a syntax error later on as... something isn't
-        // escaped it seems?
-        //
-        // Instead of attempting to fix this problem in upstream CMake and/or
-        // LLVM/LLD we just hack around it here. This thin wrapper will take the
-        // output from llvm-config and replace all instances of `\` with `/` to
-        // ensure we don't hit the same bugs with escaping. It means that you
-        // can't build on a system where your paths require `\` on Windows, but
-        // there's probably a lot of reasons you can't do that other than this.
-        let llvm_config_shim = env::current_exe().unwrap().with_file_name("llvm-config-wrapper");
-
         cfg.out_dir(&out_dir)
             .profile("Release")
-            .env("LLVM_CONFIG_REAL", &llvm_config)
-            .define("LLVM_CONFIG_PATH", llvm_config_shim)
+            .define("LLVM_CONFIG_PATH", &llvm_config)
             .define("LLVM_INCLUDE_TESTS", "OFF");
 
         // While we're using this horrible workaround to shim the execution of
