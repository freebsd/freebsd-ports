--- cgmb.c.orig	Fri Sep 13 02:57:17 1991
+++ cgmb.c	Sat Jun 16 01:08:42 2007
@@ -2,7 +2,12 @@
 #include <ctype.h>
 #include <math.h>
 #include <stdio.h>
+#include <string.h>
 #include "defs.h"
+
+static flush_cmd();
+static cb_fixed();
+
 #define byte_size 8
 #define byte_mask 255
 /* module for CGM binary output */
