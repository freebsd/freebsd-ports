--- support/ode-0.039/configurator.c.orig	Sat Jan 17 16:34:29 2004
+++ support/ode-0.039/configurator.c	Sat Jan 17 16:35:46 2004
@@ -249,7 +249,11 @@
 #define NUM_HEADERS 8
 char *header_files[NUM_HEADERS] = {
   "stdio.h", "stdlib.h", "math.h", "string.h",
-  "stdarg.h", "malloc.h", "alloca.h",
+  "stdarg.h",
+#ifndef __FreeBSD__ 
+  "malloc.h",
+#endif
+  "alloca.h",
   "ieeefp.h"		// Solaris needs this apparently
 };
 int header_used[NUM_HEADERS];
