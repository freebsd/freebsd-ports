--- camlibs/ptp2/config.c.orig	Tue Dec 12 18:43:53 2006
+++ camlibs/ptp2/config.c	Tue Dec 12 19:00:45 2006
@@ -19,6 +19,8 @@
  */
 #include "config.h"
 
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
