--- gdb/i386fbsd-tdep.c.orig	Sun Apr 15 00:24:05 2007
+++ gdb/i386fbsd-tdep.c	Sun Apr 15 00:24:26 2007
@@ -45,7 +45,7 @@
 CORE_ADDR i386fbsd_sigtramp_end_addr = 0xbfbfdff0;
 
 /* From <machine/signal.h>.  */
-static int i386fbsd_sc_reg_offset[] =
+int i386fbsd_sc_reg_offset[] =
 {
   8 + 14 * 4,			/* %eax */
   8 + 13 * 4,			/* %ecx */
