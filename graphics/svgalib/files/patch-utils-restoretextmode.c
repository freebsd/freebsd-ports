--- utils/restoretextmode.c.orig	2011-07-01 01:40:19.000000000 +0200
+++ utils/restoretextmode.c	2011-07-01 01:40:32.000000000 +0200
@@ -14,7 +14,7 @@
 
 unsigned char regs[MAX_REGS];
 
-void
+int
 main (int argc, char *argv[])
 {
   vga_init ();
