--- io.c.orig	Thu Jul 18 02:22:05 1991
+++ io.c	Sat Jun 16 02:17:10 2007
@@ -2,6 +2,8 @@
 /* all rights reserved */
 /* handle the I/O in this module */
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include "defs.h"
 static int list_io;	/* do some listing */
 #define max_str 128
@@ -80,7 +82,7 @@
 static FILE *inptr = NULL, *outptr, *dvifile;	/* input and output pointers */
 #endif
 static int block_size, record_size;
-unsigned char  *realloc(), *allocate_mem();
+unsigned char  *allocate_mem();
 #define max_b_size 1024
 static int out_b_size;      /* output buffer (how much can use) */
      static int b_ind = 0;               /* index into array */
