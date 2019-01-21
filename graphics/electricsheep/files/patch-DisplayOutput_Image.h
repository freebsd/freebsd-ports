--- DisplayOutput/Image.h.orig	2018-06-21 01:41:46 UTC
+++ DisplayOutput/Image.h
@@ -8,7 +8,7 @@
 #include	"AlignedBuffer.h"
 
 #ifdef LINUX_GNU
-#include <endian.h>
+#include <sys/endian.h>
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #define __LITTLE_ENDIAN__ __LITTLE_ENDIAN
 #undef __BIG_ENDIAN__
