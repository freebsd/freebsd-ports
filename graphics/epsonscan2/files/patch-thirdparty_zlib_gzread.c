--- thirdparty/zlib/gzread.c.orig	2021-11-25 00:56:54 UTC
+++ thirdparty/zlib/gzread.c
@@ -4,6 +4,7 @@
  */
 
 #include "gzguts.h"
+#include <unistd.h>
 
 /* Local functions */
 local int gz_load OF((gz_statep, unsigned char *, unsigned, unsigned *));
