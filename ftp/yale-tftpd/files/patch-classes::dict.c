$FreeBSD$

--- classes/dict.c.orig	Fri Jun  7 23:23:47 2002
+++ classes/dict.c	Fri Jun  7 23:24:27 2002
@@ -14,6 +14,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #include <strings.h>
 extern char*	strdup();
 extern int	strcasecmp();
