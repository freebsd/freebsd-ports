--- crc.c.orig	Mon Jun  2 20:41:23 2003
+++ crc.c	Mon Jun  2 20:43:24 2003
@@ -25,7 +25,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-
+#include <sys/types.h>
 #include "crc.h"
 
 static const u_int32_t crctab[256] = {
