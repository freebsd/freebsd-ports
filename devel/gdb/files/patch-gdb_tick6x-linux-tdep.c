--- gdb/tic6x-linux-tdep.c.orig	2018-03-15 16:29:54.131451000 +0100
+++ gdb/tic6x-linux-tdep.c	2018-03-15 16:30:19.640674000 +0100
@@ -137,7 +137,7 @@
   4,
   {
     {0x000045aa, 0x0fffffff},	/* mvk .S2 139,b0 */
-    {0x10000000, -1},		/* swe */
+    {0x10000000, static_cast<ULONGEST>(-1)},		/* swe */
     {TRAMP_SENTINEL_INSN}
   },
   tic6x_linux_rt_sigreturn_init
