--- gdb/ppc-nbsd-tdep.c.orig	2018-03-15 13:48:32.041494000 +0100
+++ gdb/ppc-nbsd-tdep.c	2018-03-15 13:50:31.332926000 +0100
@@ -137,14 +137,14 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { 0x3821fff0, -1 },		/* add r1,r1,-16 */
-    { 0x4e800021, -1 },		/* blrl */
-    { 0x38610018, -1 },		/* addi r3,r1,24 */
-    { 0x38000127, -1 },		/* li r0,295 */
-    { 0x44000002, -1 },		/* sc */
-    { 0x38000001, -1 },		/* li r0,1 */
-    { 0x44000002, -1 },		/* sc */
-    { TRAMP_SENTINEL_INSN, -1 }
+    { 0x3821fff0, static_cast<ULONGEST>(-1) },		/* add r1,r1,-16 */
+    { 0x4e800021, static_cast<ULONGEST>(-1) },		/* blrl */
+    { 0x38610018, static_cast<ULONGEST>(-1) },		/* addi r3,r1,24 */
+    { 0x38000127, static_cast<ULONGEST>(-1) },		/* li r0,295 */
+    { 0x44000002, static_cast<ULONGEST>(-1) },		/* sc */
+    { 0x38000001, static_cast<ULONGEST>(-1) },		/* li r0,1 */
+    { 0x44000002, static_cast<ULONGEST>(-1) },		/* sc */
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   ppcnbsd_sigtramp_cache_init
 };
@@ -156,14 +156,14 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { 0x3821fff0, -1 },		/* add r1,r1,-16 */
-    { 0x4e800021, -1 },		/* blrl */
-    { 0x38610010, -1 },		/* addi r3,r1,16 */
-    { 0x38000127, -1 },		/* li r0,295 */
-    { 0x44000002, -1 },		/* sc */
-    { 0x38000001, -1 },		/* li r0,1 */
-    { 0x44000002, -1 },		/* sc */
-    { TRAMP_SENTINEL_INSN, -1 }
+    { 0x3821fff0, static_cast<ULONGEST>(-1) },		/* add r1,r1,-16 */
+    { 0x4e800021, static_cast<ULONGEST>(-1) },		/* blrl */
+    { 0x38610010, static_cast<ULONGEST>(-1) },		/* addi r3,r1,16 */
+    { 0x38000127, static_cast<ULONGEST>(-1) },		/* li r0,295 */
+    { 0x44000002, static_cast<ULONGEST>(-1) },		/* sc */
+    { 0x38000001, static_cast<ULONGEST>(-1) },		/* li r0,1 */
+    { 0x44000002, static_cast<ULONGEST>(-1) },		/* sc */
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   ppcnbsd_sigtramp_cache_init
 };
