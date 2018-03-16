--- gdb/sparc64-linux-tdep.c.orig	2018-03-15 16:48:31.376247000 +0100
+++ gdb/sparc64-linux-tdep.c	2018-03-15 16:49:05.405119000 +0100
@@ -64,9 +64,9 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { 0x82102065, -1 },		/* mov __NR_rt_sigreturn, %g1 */
-    { 0x91d0206d, -1 },		/* ta  0x6d */
-    { TRAMP_SENTINEL_INSN, -1 }
+    { 0x82102065, static_cast<ULONGEST>(-1) },		/* mov __NR_rt_sigreturn, %g1 */
+    { 0x91d0206d, static_cast<ULONGEST>(-1) },		/* ta  0x6d */
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   sparc64_linux_sigframe_init
 };
