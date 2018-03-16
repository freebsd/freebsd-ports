--- gdb/microblaze-linux-tdep.c.orig	2018-03-15 11:06:05.114101000 +0100
+++ gdb/microblaze-linux-tdep.c	2018-03-15 11:06:36.384643000 +0100
@@ -107,8 +107,8 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { 0x31800077, -1 }, /* addik R12,R0,119.  */
-    { 0xb9cc0008, -1 }, /* brki R14,8.  */
+    { 0x31800077, static_cast<ULONGEST>(-1) }, /* addik R12,R0,119.  */
+    { 0xb9cc0008, static_cast<ULONGEST>(-1) }, /* brki R14,8.  */
     { TRAMP_SENTINEL_INSN },
   },
   microblaze_linux_sighandler_cache_init
