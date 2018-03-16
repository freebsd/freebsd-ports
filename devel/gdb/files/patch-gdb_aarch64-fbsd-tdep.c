--- gdb/aarch64-fbsd-tdep.c.orig	2018-03-15 16:39:29.951492000 +0100
+++ gdb/aarch64-fbsd-tdep.c	2018-03-15 16:40:31.553135000 +0100
@@ -118,11 +118,11 @@
   SIGTRAMP_FRAME,
   4,
   {
-    {0x910003e0, -1},		/* mov  x0, sp  */
-    {0x91014000, -1},		/* add  x0, x0, #SF_UC  */
-    {0xd2803428, -1},		/* mov  x8, #SYS_sigreturn  */
-    {0xd4000001, -1},		/* svc  0x0  */
-    {TRAMP_SENTINEL_INSN, -1}
+    {0x910003e0, static_cast<ULONGEST>(-1)},		/* mov  x0, sp  */
+    {0x91014000, static_cast<ULONGEST>(-1)},		/* add  x0, x0, #SF_UC  */
+    {0xd2803428, static_cast<ULONGEST>(-1)},		/* mov  x8, #SYS_sigreturn  */
+    {0xd4000001, static_cast<ULONGEST>(-1)},		/* svc  0x0  */
+    {TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1)}
   },
   aarch64_fbsd_sigframe_init
 };
