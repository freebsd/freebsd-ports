--- xmalloc.c.orig	2015-05-04 09:15:45 UTC
+++ xmalloc.c
@@ -17,6 +17,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 
 #include "log.h"
 #include "xmalloc.h"
