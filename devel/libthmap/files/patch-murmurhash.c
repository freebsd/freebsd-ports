--- murmurhash.c.orig	2020-08-28 21:41:19 UTC
+++ murmurhash.c
@@ -9,7 +9,7 @@
  */
 
 #include <inttypes.h>
-#include <endian.h>
+#include <sys/endian.h>
 
 #include "utils.h"
 
