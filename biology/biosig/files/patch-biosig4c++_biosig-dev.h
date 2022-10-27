--- biosig4c++/biosig-dev.h.orig	2022-10-08 10:54:15 UTC
+++ biosig4c++/biosig-dev.h
@@ -35,6 +35,8 @@
 #include <time.h>
 #include "physicalunits.h"
 
+#include <sys/endian.h>
+#include <machine/endian.h> // for betoh16, etc.
 
 #ifdef __cplusplus
 extern "C" {
@@ -549,6 +551,12 @@ HDRTYPE* sopen_extended(const char* FileName, const ch
 #elif defined(__linux__) 
 #  include <endian.h>
 #  include <byteswap.h>
+
+#elif defined(__FreeBSD__) 
+#  include <machine/endian.h>
+#  define __BIG_ENDIAN _BIG_ENDIAN
+#  define __LITTLE_ENDIAN _LITTLE_ENDIAN
+#  define __BYTE_ORDER _BYTE_ORDER
 
 #elif defined(__FreeBSD__)
 #  include <machine/endian.h>
