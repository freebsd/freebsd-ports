--- gdb/arm-fbsd-tdep.c.orig	2018-03-15 10:31:28.468820000 +0100
+++ gdb/arm-fbsd-tdep.c	2018-03-15 10:39:51.558505000 +0100
@@ -123,11 +123,11 @@
   SIGTRAMP_FRAME,
   4,
   {
-    {0xe1a0000d, -1},		/* mov  r0, sp  */
-    {0xe2800040, -1},		/* add  r0, r0, #SIGF_UC  */
-    {0xe59f700c, -1},		/* ldr  r7, [pc, #12]  */
-    {0xef0001a1, -1},		/* swi  SYS_sigreturn  */
-    {TRAMP_SENTINEL_INSN, -1}
+    {0xe1a0000d, static_cast<ULONGEST>(-1)},		/* mov  r0, sp  */
+    {0xe2800040, static_cast<ULONGEST>(-1)},		/* add  r0, r0, #SIGF_UC  */
+    {0xe59f700c, static_cast<ULONGEST>(-1)},		/* ldr  r7, [pc, #12]  */
+    {0xef0001a1, static_cast<ULONGEST>(-1)},		/* swi  SYS_sigreturn  */
+    {TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1)}
   },
   arm_fbsd_sigframe_init
 };
