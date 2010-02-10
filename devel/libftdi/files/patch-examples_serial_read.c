--- examples/serial_read.c.orig	2010-02-03 14:19:13.000000000 +0200
+++ examples/serial_read.c	2010-02-03 14:19:19.000000000 +0200
@@ -6,6 +6,7 @@
 */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <getopt.h>
 #include <ftdi.h>
