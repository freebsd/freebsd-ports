--- pcie9842.c.orig	2014-06-27 17:35:42.000000000 -0700
+++ pcie9842.c	2014-06-27 17:35:49.000000000 -0700
@@ -2,7 +2,6 @@
 #if PCIE9842_PRESENT == 1
 #include <stdio.h>
 #include <stdlib.h>
-#include <malloc.h>
 #include <unistd.h>
 #include <pthread.h>
 #include <string.h>
