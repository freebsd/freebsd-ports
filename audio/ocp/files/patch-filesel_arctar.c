--- filesel/arctar.c.orig	Sun Apr 24 02:06:12 2005
+++ filesel/arctar.c	Sun Apr 24 02:07:06 2005
@@ -13,9 +13,6 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#ifndef __linux
-#include <sys/resource.h>
-#endif
 #include <sys/signal.h>
 #include <sys/stat.h>
 #include <sys/time.h>
