--- pkras.c.orig	Thu Jul 18 02:22:07 1991
+++ pkras.c	Sat Jun 16 01:31:42 2007
@@ -2,7 +2,12 @@
 /* module to decode a PK format packed raster font description */
 /* globals for pk processing */
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include "defs.h"
+
+static dim_str();
+
 #define NO_FONTS 8	/* the number of font styles pre-defined */
 #define max_mags 100
 #define pts_in 72.27
@@ -32,7 +37,6 @@
 static int rot_bytes_allocated = r_b_allocated;
 static char ras_array[r_b_allocated], rot_array[r_b_allocated];
 static char *ras_ptr = ras_array, *rot_ptr = rot_array;
-extern char *realloc();
 
 #define max_char_stor 100000
 static unsigned char char_stor[max_char_stor];	/* store character definitions */
