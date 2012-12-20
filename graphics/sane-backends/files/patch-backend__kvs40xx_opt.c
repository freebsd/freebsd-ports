--- backend/kvs40xx_opt.c.orig	2012-08-10 09:33:29.000000000 +0900
+++ backend/kvs40xx_opt.c	2012-08-29 16:57:47.000000000 +0900
@@ -8,6 +8,7 @@
 
 #include "../include/sane/config.h"
 
+#include <stdlib.h>
 #include <string.h>
 #define DEBUG_DECLARE_ONLY
 #define BACKEND_NAME kvs40xx
