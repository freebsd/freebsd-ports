
$FreeBSD$

--- geta/geta.c.orig	Wed Dec 18 02:18:00 2002
+++ geta/geta.c	Wed Dec 18 02:18:16 2002
@@ -7,6 +7,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 char *progname;
 int errors = 0;			/* number of errors */
