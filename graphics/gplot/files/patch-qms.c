--- qms.c.orig	Thu Jul 18 02:22:08 1991
+++ qms.c	Sat Jun 16 02:01:07 2007
@@ -2,7 +2,12 @@
 #include <ctype.h>
 #include <math.h>
 #include <stdio.h>
+#include <string.h>
 #include "defs.h"
+
+static set_fill();
+static float grey_col();
+
 #define byte_size 8
 #define out_ln(instr) {out_string(instr); fb();}
 
