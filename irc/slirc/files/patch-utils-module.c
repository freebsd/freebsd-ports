--- utils-module.c.orig	Mon Aug 23 01:39:11 1999
+++ utils-module.c	Sat Jan  6 08:46:47 2001
@@ -11,6 +11,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <slang.h>
+#include <sys/types.h>
 
 /* this was just to verify that cp0 will be an slstring
 static int is_same(char *cp0)
