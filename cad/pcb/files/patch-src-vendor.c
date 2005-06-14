--- src/vendor.c.orig	Mon Jun 13 09:05:39 2005
+++ src/vendor.c	Mon Jun 13 09:05:55 2005
@@ -26,6 +26,8 @@
 #include "config.h"
 #endif
 
+#include <sys/types.h>
+
 #include <ctype.h>
 #include <math.h>
 #include <stdio.h>
