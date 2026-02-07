--- def.h.orig	2013-12-12 17:16:34.000000000 +0100
+++ def.h	2013-12-12 17:17:40.000000000 +0100
@@ -13,6 +13,8 @@
 #define DEF_DEF
 #define LINT_ARGS   1		/* enable lint type checking */
 #include        <stdio.h>
+#include        <stdlib.h>
+#include        <string.h>
 
 #ifdef UNIX
 #include        <sys/types.h>
