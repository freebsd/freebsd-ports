--- libxfs/crc32.c.orig	2015-07-24 04:28:04 UTC
+++ libxfs/crc32.c
@@ -33,6 +33,7 @@
  * match the hardware acceleration available on Intel CPUs.
  */
 
+#include <inttypes.h>
 #include <libxfs.h>
 #include "crc32defs.h"
 
