--- crc.c.orig	2003-01-10 22:19:35 UTC
+++ crc.c
@@ -25,7 +25,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-
+#include <sys/types.h>
 #include "crc.h"
 
 static const u_int32_t crctab[256] = {
