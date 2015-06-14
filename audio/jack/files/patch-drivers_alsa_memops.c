--- drivers/alsa/memops.c.orig	2013-10-04 00:45:25 UTC
+++ drivers/alsa/memops.c
@@ -30,7 +30,7 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <limits.h>
-#include <endian.h>
+#include <sys/endian.h>
 
 #include "memops.h"
 
