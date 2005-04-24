--- dev/mix.c.orig	Sat Apr 23 23:13:56 2005
+++ dev/mix.c	Sat Apr 23 23:14:04 2005
@@ -13,6 +13,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 #include <unistd.h>
 #include "mcp.h"
