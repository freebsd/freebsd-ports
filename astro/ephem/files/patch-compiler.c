diff -u compiler.c.orig compiler.c
--- compiler.c.orig	Sun Jan 21 20:26:09 2007
+++ compiler.c	Sun Jan 21 20:33:59 2007
@@ -13,6 +13,14 @@
 #include <stdlib.h>
 #endif
 #include "screen.h"
+#include <stdio.h>
+#include <string.h>
+
+static next_token();
+static skip_double();
+static compile(int prec);
+static execute(double *result);
+static parse_fieldname();
 
 /* parser tokens and opcodes, as necessary */
 #define	HALT	0	/* good value for HALT since program is inited to 0 */
