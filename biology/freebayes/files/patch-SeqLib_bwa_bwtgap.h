--- SeqLib/bwa/bwtgap.h.orig	2018-03-23 18:49:18 UTC
+++ SeqLib/bwa/bwtgap.h
@@ -3,6 +3,7 @@
 
 #include "bwt.h"
 #include "bwtaln.h"
+#include <sys/types.h>
 
 typedef struct { // recursion stack
 	u_int32_t info; // score<<21 | i
