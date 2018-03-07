--- contrib/ucw/mempool-fmt.c.orig     2018-03-06 23:36:10 UTC
+++ contrib/ucw/mempool-fmt.c
@@ -11,7 +11,7 @@
 #include <ucw/lib.h>
 #include <ucw/mempool.h>
 
-#include <alloca.h>
+#include "alloc.h"
 #include <stdio.h>
 #include <string.h>
 
