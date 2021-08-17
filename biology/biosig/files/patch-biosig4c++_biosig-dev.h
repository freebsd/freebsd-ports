--- biosig4c++/biosig-dev.h.orig	2021-08-13 09:17:15 UTC
+++ biosig4c++/biosig-dev.h
@@ -35,6 +35,8 @@
 #include <time.h>
 #include "physicalunits.h"
 
+#include <sys/endian.h>
+#include <machine/endian.h> // for betoh16, etc.
 
 #ifdef __cplusplus
 extern "C" {
@@ -549,6 +551,9 @@ HDRTYPE* sopen_extended(const char* FileName, const ch
 #elif defined(__linux__) 
 #  include <endian.h>
 #  include <byteswap.h>
+
+#elif defined(__FreeBSD__) 
+#  include <machine/endian.h>
 
 #elif defined(__GLIBC__)       // for Hurd
 #  include <endian.h>
