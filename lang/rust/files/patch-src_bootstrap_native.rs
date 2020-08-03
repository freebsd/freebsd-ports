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

--- src/bootstrap/native.rs.orig	2020-07-26 16:11:04 UTC
+++ src/bootstrap/native.rs
@@ -324,6 +324,11 @@ fn configure_cmake(
     // LLVM and LLD builds can produce a lot of those and hit CI limits on log size.
     cfg.define("CMAKE_INSTALL_MESSAGE", "LAZY");
 
+    // Do not allow the user's value of DESTDIR to influence where
+    // LLVM will install itself. LLVM must always be installed in our
+    // own build directories.
+    cfg.env("DESTDIR", "");
+
     if builder.config.ninja {
         cfg.generator("Ninja");
     }
