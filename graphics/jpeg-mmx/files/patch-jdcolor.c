--- jdcolor.c.orig	Mon Nov  1 23:58:16 2004
+++ jdcolor.c	Tue Nov  2 00:01:30 2004
@@ -129,9 +129,9 @@
 static const int64 bpte1 = 0x7168e9f97168e9f9; // for cb (Cb/b, Cb/g, Cb/b, Cb/g)
 static const int64 bpte2 = 0xd21a59bad21a59ba; // for cr (Cr/g, Cr/r, Cr/g, Cr/r)
 #else
-static const int64 te0 = 0x0200020002000200; // -128 << 2
-static const int64 te1 = 0xe9fa7168e9fa7168; // for cb
-static const int64 te2 = 0x59bad24d59bad24d; // for cr
+ const int64 te0 = 0x0200020002000200; // -128 << 2
+ const int64 te1 = 0xe9fa7168e9fa7168; // for cb
+ const int64 te2 = 0x59bad24d59bad24d; // for cr
 #endif
 //static const int64 te2 = 0x59ba524b59ba524b; // for cr
 /* How to calculate the constants (see constants from above for YCbCr->RGB):
