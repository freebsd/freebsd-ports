--- io/iob_prefetch.c.orig	Sat Feb 21 17:56:29 2004
+++ io/iob_prefetch.c	Sat Feb 21 17:56:49 2004
@@ -1,5 +1,6 @@
 #include "iob_internal.h"
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 
 void iob_prefetch(io_batch* b,uint64 bytes) {
