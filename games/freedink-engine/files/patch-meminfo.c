--- src/meminfo.c.orig	2013-08-14 02:51:44.000000000 -0700
+++ src/meminfo.c	2013-08-14 02:51:55.000000000 -0700
@@ -24,7 +24,7 @@
 #include <config.h>
 #endif
 
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "log.h"
 
