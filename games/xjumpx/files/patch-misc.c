--- misc.c.orig	2001-08-14 20:10:46.000000000 +0800
+++ misc.c	2011-09-05 15:15:48.000000000 +0800
@@ -31,11 +31,13 @@
 **	May 25, 2000 Ver 1.0
 */
 
-#include<stdio.h>
-#include<stdlib.h>
-#include<errno.h>
-#include<sys/types.h>
-#include<pwd.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <errno.h>
+#include <sys/types.h>
+#include <pwd.h>
+#include <ctype.h>
 
 static long Seed;
 
