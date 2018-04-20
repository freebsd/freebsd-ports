--- SeqLib/bwa/bwt_lite.c.orig	2018-03-23 18:49:48 UTC
+++ SeqLib/bwa/bwt_lite.c
@@ -1,6 +1,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
+#include <sys/types.h>
 #include "bwt_lite.h"
 
 #ifdef USE_MALLOC_WRAPPERS
