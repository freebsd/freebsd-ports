--- Src/spin.y.orig	2019-10-04 20:02:16 UTC
+++ Src/spin.y
@@ -13,6 +13,7 @@
 #include <unistd.h>
 #endif
 #include <stdarg.h>
+#include <stdlib.h>
 
 #define YYMAXDEPTH	20000	/* default is 10000 */
 #define YYDEBUG		0
