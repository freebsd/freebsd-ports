--- svg.c.orig	2019-09-08 12:19:55 UTC
+++ svg.c
@@ -7,9 +7,7 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>
-#ifndef XC_WIN32
 #include <unistd.h>
-#endif
 #include <math.h>
 #include <limits.h>
 #include <sys/stat.h>
