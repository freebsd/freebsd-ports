--- third_party/roaring_bitmap/roaring.c.orig	2025-03-13 23:38:46 UTC
+++ third_party/roaring_bitmap/roaring.c
@@ -55,6 +55,7 @@
  */
 
 #include "roaring.h"
+#include <sys/endian.h>
 
 /* used for http://dmalloc.com/ Dmalloc - Debug Malloc Library */
 #ifdef DMALLOC
