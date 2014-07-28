diff -druN svgalib-1.4.2.orig/src/nv3.c src/nv3.c
--- svgalib-1.4.2.orig/src/nv3.c	Fri Aug 25 04:39:39 2000
+++ src/nv3.c	Fri Aug 25 04:39:57 2000
@@ -17,6 +17,7 @@
 #include <stdlib.h>
 #include <stdio.h>		/* for printf */
 #include <string.h>		/* for memset */
+#include <sys/types.h>
 #include <sys/mman.h>		
 #include <fcntl.h>
 #include <math.h>
