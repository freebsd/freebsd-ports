--- gdb/tilegx-linux-tdep.c.orig	2018-03-15 16:31:44.623131000 +0100
+++ gdb/tilegx-linux-tdep.c	2018-03-15 16:32:29.603585000 +0100
@@ -65,9 +65,9 @@
   SIGTRAMP_FRAME,
   8,
   {
-    { 0x00045fe551483000ULL, -1 }, /* { moveli r10, 139 } */
-    { 0x286b180051485000ULL, -1 }, /* { swint1 } */
-    { TRAMP_SENTINEL_INSN, -1 }
+    { 0x00045fe551483000ULL, static_cast<ULONGEST>(-1) }, /* { moveli r10, 139 } */
+    { 0x286b180051485000ULL, static_cast<ULONGEST>(-1) }, /* { swint1 } */
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   tilegx_linux_sigframe_init
 };
