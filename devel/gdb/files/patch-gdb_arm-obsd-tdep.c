--- gdb/arm-obsd-tdep.c.orig	2018-03-15 10:43:44.244835000 +0100
+++ gdb/arm-obsd-tdep.c	2018-03-15 10:44:36.608679000 +0100
@@ -58,11 +58,11 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { 0xe28d0010, -1 },		/* add     r0, sp, #16 */
-    { 0xef000067, -1 },		/* swi     SYS_sigreturn */
-    { 0xef000001, -1 },		/* swi     SYS_exit */
-    { 0xeafffffc, -1 },		/* b       . - 8 */
-    { TRAMP_SENTINEL_INSN, -1 }
+    { 0xe28d0010, static_cast<ULONGEST>(-1) },		/* add     r0, sp, #16 */
+    { 0xef000067, static_cast<ULONGEST>(-1) },		/* swi     SYS_sigreturn */
+    { 0xef000001, static_cast<ULONGEST>(-1) },		/* swi     SYS_exit */
+    { 0xeafffffc, static_cast<ULONGEST>(-1) },		/* b       . - 8 */
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   armobsd_sigframe_init
 };
