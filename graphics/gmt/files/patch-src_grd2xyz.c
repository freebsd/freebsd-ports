--- src/grd2xyz.c.orig	2022-01-03 22:31:11 UTC
+++ src/grd2xyz.c
@@ -23,6 +23,7 @@
  * Version:	6 API
  */
 
+#include "gmt_common_byteswap.h"
 #include "gmt_dev.h"
 
 #define THIS_MODULE_CLASSIC_NAME	"grd2xyz"
