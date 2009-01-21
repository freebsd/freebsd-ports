--- src/wgrib.c.orig	2009-01-20 21:11:09.000000000 -0800
+++ src/wgrib.c	2009-01-20 21:11:28.000000000 -0800
@@ -6,6 +6,7 @@
 #include <config.h>
 #endif
 
+#include <sys/types.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
