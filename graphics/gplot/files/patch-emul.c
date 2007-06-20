--- emul.c.orig	Thu Jul 18 02:22:01 1991
+++ emul.c	Sat Jun 16 01:04:15 2007
@@ -5,6 +5,8 @@
 #include <stdio.h>
 #include "defs.h"
 
+static em_arc();
+
 /* store these pointers to allow lookups into the CGM data structures */
 static struct one_opt 		*popt;	/* the command line options, in only */
 static struct mf_d_struct 	*pc1;	/* the class 1 elements, in only */
