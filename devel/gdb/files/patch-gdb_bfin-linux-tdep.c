--- gdb/bfin-linux-tdep.c.orig	2018-03-15 10:45:37.746477000 +0100
+++ gdb/bfin-linux-tdep.c	2018-03-15 10:46:02.925435000 +0100
@@ -121,7 +121,7 @@
   {
     { 0x00ADE128, 0xffffffff },	/* P0 = __NR_rt_sigreturn; */
     { 0x00A0, 0xffff },		/* EXCPT 0; */
-    { TRAMP_SENTINEL_INSN, -1 },
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) },
   },
   bfin_linux_sigframe_init,
 };
