--- gcin2tab.c.orig	Tue Nov  1 15:17:21 2005
+++ gcin2tab.c	Tue Nov  1 15:17:21 2005
@@ -4,8 +4,11 @@
 */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <stdarg.h>
 #include <sys/types.h>
+#include <sys/param.h>
+#include <sys/stat.h>
 #include <string.h>
 #include "gcin.h"
 #include "gtab.h"
