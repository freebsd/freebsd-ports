--- third_party/roaring_bitmap/roaring.c.orig	2026-04-29 00:05:06 UTC
+++ third_party/roaring_bitmap/roaring.c
@@ -55,6 +55,7 @@
  */
 
 #include "roaring.h"
+#include <sys/endian.h>
 
 /* used for http://dmalloc.com/ Dmalloc - Debug Malloc Library */
 #ifdef DMALLOC
