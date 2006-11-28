--- lib/init.c.orig	Tue Nov 28 00:05:18 2006
+++ lib/init.c	Tue Nov 28 00:06:02 2006
@@ -1,6 +1,7 @@
 /* $Id: init.c,v 1.31 1997/07/07 03:40:34 phil Exp $ */
 
 #include <stdio.h>			/* for usage! */
+#include <stdlib.h>
 #include <signal.h>
 
 #include "h.h"
@@ -17,7 +18,6 @@
 #endif
 
 extern char *dynamic();
-extern char *malloc();
 
 #define NDYNAMIC 25000			/* default dynamic region size */
 
