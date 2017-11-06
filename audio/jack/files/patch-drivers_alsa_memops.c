--- drivers/alsa/memops.c.orig	2016-02-23 15:13:53 UTC
+++ drivers/alsa/memops.c
@@ -30,7 +30,7 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <limits.h>
-#include <endian.h>
+#include <sys/endian.h>
 
 #include "memops.h"
 
