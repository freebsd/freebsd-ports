--- cnv/ppmtorle.c.orig	1992-03-05 04:29:44.000000000 +0900
+++ cnv/ppmtorle.c	2012-10-16 01:05:15.000000000 +0900
@@ -37,6 +37,7 @@
 #define NO_DECLARE_MALLOC	/* ppm.h does it */
 #include "rle.h"
 #include <stdio.h>
+#include <string.h>
 #include <ppm.h>
 
 #define VPRINTF if (verbose || header) fprintf
