--- gdb/aarch64-linux-tdep.c.orig	2018-03-15 16:42:39.445907000 +0100
+++ gdb/aarch64-linux-tdep.c	2018-03-15 16:43:15.167745000 +0100
@@ -176,12 +176,12 @@
   {
     /* movz x8, 0x8b (S=1,o=10,h=0,i=0x8b,r=8)
        Soo1 0010 1hhi iiii iiii iiii iiir rrrr  */
-    {0xd2801168, -1},
+    {0xd2801168, static_cast<ULONGEST>(-1)},
 
     /* svc  0x0      (o=0, l=1)
        1101 0100 oooi iiii iiii iiii iii0 00ll  */
-    {0xd4000001, -1},
-    {TRAMP_SENTINEL_INSN, -1}
+    {0xd4000001, static_cast<ULONGEST>(-1)},
+    {TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1)}
   },
   aarch64_linux_sigframe_init
 };
