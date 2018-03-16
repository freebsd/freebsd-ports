--- gdb/mips64-obsd-tdep.c.orig	2018-03-15 16:47:34.626536000 +0100
+++ gdb/mips64-obsd-tdep.c	2018-03-15 16:48:17.150853000 +0100
@@ -127,11 +127,11 @@
   SIGTRAMP_FRAME,
   MIPS_INSN32_SIZE,
   {
-    { 0x67a40020, -1 },		/* daddiu  a0,sp,32 */
-    { 0x24020067, -1 },		/* li      v0,103 */
-    { 0x0000000c, -1 },		/* syscall */
-    { 0x0000000d, -1 },		/* break */
-    { TRAMP_SENTINEL_INSN, -1 }
+    { 0x67a40020, static_cast<ULONGEST>(-1) },		/* daddiu  a0,sp,32 */
+    { 0x24020067, static_cast<ULONGEST>(-1) },		/* li      v0,103 */
+    { 0x0000000c, static_cast<ULONGEST>(-1) },		/* syscall */
+    { 0x0000000d, static_cast<ULONGEST>(-1) },		/* break */
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   mips64obsd_sigframe_init
 };
