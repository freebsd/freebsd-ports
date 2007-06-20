--- carray.c.orig	Fri Sep 13 02:57:13 1991
+++ carray.c	Sat Jun 16 02:27:51 2007
@@ -3,6 +3,11 @@
 /* all rights reserved */
 #include "defs.h"
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+
+static do_line();
+
 /* a few globals */
 #define byte_size 8
 unsigned char *allocate_mem();			/* in utils.c */
