--- gdb/mn10300-linux-tdep.c.orig	2018-03-15 11:17:21.462824000 +0100
+++ gdb/mn10300-linux-tdep.c	2018-03-15 11:20:05.266582000 +0100
@@ -476,13 +476,13 @@
   1,
   {
     /* mov     119,d0 */
-    { 0x2c, -1 },
-    { 0x77, -1 },
-    { 0x00, -1 },
+    { 0x2c, static_cast<ULONGEST>(-1) },
+    { 0x77, static_cast<ULONGEST>(-1) },
+    { 0x00, static_cast<ULONGEST>(-1) },
     /* syscall 0 */
-    { 0xf0, -1 },
-    { 0xe0, -1 },
-    { TRAMP_SENTINEL_INSN, -1 }
+    { 0xf0, static_cast<ULONGEST>(-1) },
+    { 0xe0, static_cast<ULONGEST>(-1) },
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   am33_linux_sigframe_cache_init
 };
@@ -492,13 +492,13 @@
   1,
   {
     /* mov     173,d0 */
-    { 0x2c, -1 },
-    { 0xad, -1 },
-    { 0x00, -1 },
+    { 0x2c, static_cast<ULONGEST>(-1) },
+    { 0xad, static_cast<ULONGEST>(-1) },
+    { 0x00, static_cast<ULONGEST>(-1) },
     /* syscall 0 */
-    { 0xf0, -1 },
-    { 0xe0, -1 },
-    { TRAMP_SENTINEL_INSN, -1 }
+    { 0xf0, static_cast<ULONGEST>(-1) },
+    { 0xe0, static_cast<ULONGEST>(-1) },
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   am33_linux_sigframe_cache_init
 };
