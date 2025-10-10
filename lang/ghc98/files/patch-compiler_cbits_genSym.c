From a7402f4129e1137b1d729b1aedeb1508881c9eff Mon Sep 17 00:00:00 2001
From: Ben Gamari <ben@well-typed.com>
Date: Tue, 17 Dec 2024 11:48:52 -0500
Subject: [PATCH] compiler: Fix CPP guards around ghc_unique_counter64

The `ghc_unique_counter64` symbol was introduced in the RTS in the
64-bit unique refactor (!10568) which has been backported to %9.6.7 and
%9.8.4. Update the CPP to reflect this.

Fixes #25576.

(cherry picked from commit 595013d41464c1e328369bb81ce0ea2814e91b68)
--- compiler/cbits/genSym.c.orig	2024-11-27 22:03:56 UTC
+++ compiler/cbits/genSym.c
@@ -9,7 +9,19 @@
 //
 // The CPP is thus about the RTS version GHC is linked against, and not the
 // version of the GHC being built.
-#if !MIN_VERSION_GLASGOW_HASKELL(9,8,4,0)
+
+#if MIN_VERSION_GLASGOW_HASKELL(9,9,0,0)
+// Unique64 patch was present in 9.10 and later
+#define HAVE_UNIQUE64 1
+#elif !MIN_VERSION_GLASGOW_HASKELL(9,9,0,0) && MIN_VERSION_GLASGOW_HASKELL(9,8,4,0)
+// Unique64 patch was backported to 9.8.4
+#define HAVE_UNIQUE64 1
+#elif !MIN_VERSION_GLASGOW_HASKELL(9,7,0,0) && MIN_VERSION_GLASGOW_HASKELL(9,6,7,0)
+// Unique64 patch was backported to 9.6.7
+#define HAVE_UNIQUE64 1
+#endif
+
+#if !defined(HAVE_UNIQUE64)
 HsWord64 ghc_unique_counter64 = 0;
 #endif
 #if !MIN_VERSION_GLASGOW_HASKELL(9,3,0,0)
