--- src/jit/bcsave.lua.orig	2025-08-14 13:39:47 UTC
+++ src/jit/bcsave.lua
@@ -96,6 +96,8 @@ local map_arch = {
   arm64 =	{ e = "le", b = 64, m = 183, p = 0xaa64, },
   arm64be =	{ e = "be", b = 64, m = 183, },
   ppc =		{ e = "be", b = 32, m = 20, },
+  ppc64 =	{ e = "be", b = 64, m = 21, },
+  ppc64le =	{ e = "le", b = 64, m = 21, },
   mips =	{ e = "be", b = 32, m = 8, f = 0x50001006, },
   mipsel =	{ e = "le", b = 32, m = 8, f = 0x50001006, },
   mips64 =	{ e = "be", b = 64, m = 8, f = 0x80000007, },
