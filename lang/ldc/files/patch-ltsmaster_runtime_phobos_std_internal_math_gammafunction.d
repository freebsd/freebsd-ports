https://github.com/ldc-developers/phobos/commit/65b103fc08c5a58f3b0c2b56ac8650ca8e678109.patch

From 65b103fc08c5a58f3b0c2b56ac8650ca8e678109 Mon Sep 17 00:00:00 2001
From: Iain Buclaw <ibuclaw@gdcproject.org>
Date: Sat, 23 May 2015 14:05:03 +0200
Subject: [PATCH] Relax compile-time assertion in gammafunction to runtime

--- ltsmaster/runtime/phobos/std/internal/math/gammafunction.d.orig	2020-11-14 19:44:53 UTC
+++ ltsmaster/runtime/phobos/std/internal/math/gammafunction.d
@@ -1653,8 +1653,10 @@ unittest {
 real logmdigammaInverse(real y)
 {
     import std.numeric: findRoot;
-    enum maxY = logmdigamma(real.min_normal);
-    static assert(maxY > 0 && maxY <= real.max);
+    // FIXME: should be returned back to enum.
+    // Fix requires CTFEable `log` on non-x86 targets (check both LDC and GDC).
+    immutable maxY = logmdigamma(real.min_normal);
+    assert(maxY > 0 && maxY <= real.max);
 
     if (y >= maxY)
     {
