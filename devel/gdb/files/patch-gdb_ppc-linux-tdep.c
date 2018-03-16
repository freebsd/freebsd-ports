--- gdb/ppc-linux-tdep.c.orig	2018-03-15 11:56:24.120083000 +0100
+++ gdb/ppc-linux-tdep.c	2018-03-15 11:57:57.568381000 +0100
@@ -663,8 +663,8 @@
   SIGTRAMP_FRAME,
   4,
   { 
-    { 0x380000ac, -1 }, /* li r0, 172 */
-    { 0x44000002, -1 }, /* sc */
+    { 0x380000ac, static_cast<ULONGEST>(-1) }, /* li r0, 172 */
+    { 0x44000002, static_cast<ULONGEST>(-1) }, /* sc */
     { TRAMP_SENTINEL_INSN },
   },
   ppc32_linux_sigaction_cache_init
@@ -673,9 +673,9 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { 0x38210080, -1 }, /* addi r1,r1,128 */
-    { 0x380000ac, -1 }, /* li r0, 172 */
-    { 0x44000002, -1 }, /* sc */
+    { 0x38210080, static_cast<ULONGEST>(-1) }, /* addi r1,r1,128 */
+    { 0x380000ac, static_cast<ULONGEST>(-1) }, /* li r0, 172 */
+    { 0x44000002, static_cast<ULONGEST>(-1) }, /* sc */
     { TRAMP_SENTINEL_INSN },
   },
   ppc64_linux_sigaction_cache_init
@@ -684,8 +684,8 @@
   SIGTRAMP_FRAME,
   4,
   { 
-    { 0x38000077, -1 }, /* li r0,119 */
-    { 0x44000002, -1 }, /* sc */
+    { 0x38000077, static_cast<ULONGEST>(-1) }, /* li r0,119 */
+    { 0x44000002, static_cast<ULONGEST>(-1) }, /* sc */
     { TRAMP_SENTINEL_INSN },
   },
   ppc32_linux_sighandler_cache_init
@@ -694,9 +694,9 @@
   SIGTRAMP_FRAME,
   4,
   { 
-    { 0x38210080, -1 }, /* addi r1,r1,128 */
-    { 0x38000077, -1 }, /* li r0,119 */
-    { 0x44000002, -1 }, /* sc */
+    { 0x38210080, static_cast<ULONGEST>(-1) }, /* addi r1,r1,128 */
+    { 0x38000077, static_cast<ULONGEST>(-1) }, /* li r0,119 */
+    { 0x44000002, static_cast<ULONGEST>(-1) }, /* sc */
     { TRAMP_SENTINEL_INSN },
   },
   ppc64_linux_sighandler_cache_init
