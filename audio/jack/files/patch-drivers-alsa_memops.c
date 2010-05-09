--- drivers/alsa/memops.c.orig	2010-05-08 20:23:13.000000000 -0300
+++ drivers/alsa/memops.c	2010-05-08 20:23:24.000000000 -0300
@@ -30,7 +30,7 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <limits.h>
-#include <endian.h>
+#include <sys/endian.h>
 
 #include <jack/memops.h>
 
