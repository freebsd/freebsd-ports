--- tek.c.orig	Thu Jul 18 02:22:10 1991
+++ tek.c	Sat Jun 16 01:07:12 2007
@@ -1,7 +1,12 @@
 /* copyright 1987, 1988, 1989 Phil Andrews, Pittsburgh Supercomputing Center */
 #include <stdio.h>
 #include <ctype.h>
+#include <string.h>
 #include "defs.h"
+
+static save_env();
+static load_dcmap();
+
 /* macros for generic TEKTRONIX processing */
 #define eot	'\004'	/* end of file */
 #define ctrl_e	'\005'	/* enquire tty status */
