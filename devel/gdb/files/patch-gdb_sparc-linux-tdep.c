--- gdb/sparc-linux-tdep.c.orig	2018-03-15 16:27:40.393176000 +0100
+++ gdb/sparc-linux-tdep.c	2018-03-15 16:29:00.339581000 +0100
@@ -68,9 +68,9 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { 0x821020d8, -1 },		/* mov __NR_sugreturn, %g1 */
-    { 0x91d02010, -1 },		/* ta  0x10 */
-    { TRAMP_SENTINEL_INSN, -1 }
+    { 0x821020d8, static_cast<ULONGEST>(-1) },		/* mov __NR_sugreturn, %g1 */
+    { 0x91d02010, static_cast<ULONGEST>(-1) },		/* ta  0x10 */
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   sparc32_linux_sigframe_init
 };
@@ -83,9 +83,9 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { 0x82102065, -1 },		/* mov __NR_rt_sigreturn, %g1 */
-    { 0x91d02010, -1 },		/* ta  0x10 */
-    { TRAMP_SENTINEL_INSN, -1 }
+    { 0x82102065, static_cast<ULONGEST>(-1) },		/* mov __NR_rt_sigreturn, %g1 */
+    { 0x91d02010, static_cast<ULONGEST>(-1) },		/* ta  0x10 */
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   sparc32_linux_sigframe_init
 };
