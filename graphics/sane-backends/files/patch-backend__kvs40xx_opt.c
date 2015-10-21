--- backend/kvs40xx_opt.c.orig	2013-08-25 21:22:58 UTC
+++ backend/kvs40xx_opt.c
@@ -8,6 +8,7 @@
 
 #include "../include/sane/config.h"
 
+#include <stdlib.h>
 #include <string.h>
 #define DEBUG_DECLARE_ONLY
 #define BACKEND_NAME kvs40xx
