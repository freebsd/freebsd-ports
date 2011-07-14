--- utils/setmclk.c.orig	2011-07-01 01:44:52.000000000 +0200
+++ utils/setmclk.c	2011-07-01 01:45:20.000000000 +0200
@@ -41,8 +41,8 @@
 #include <vga.h>
 #include "../src/libvga.h"	/* For port I/O macros. */
 
-void
-main (void)
+int
+main(void)
 {
   vga_init ();
   if (vga_getcurrentchipset () != CIRRUS)
