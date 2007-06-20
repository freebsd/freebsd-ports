--- ps.c.orig	Wed Jun 17 02:29:19 1992
+++ ps.c	Sat Jun 16 01:05:35 2007
@@ -2,10 +2,15 @@
 #include <ctype.h>
 #include <math.h>
 #include <stdio.h>
+#include <string.h>
 #include "defs.h"
 #define byte_size 8
 #define out_ln(instr) {out_string(instr); fb();}
 #define APPENDED_MARKER -123	/* appended text coming */
+
+static send_string();
+static flush_string();
+static l_dofont();
 
 /* module for PostScript specific functions, note that we expect the device
    resolution is pxl_per_in, set by the calling program. All dimensions are expected
