--- biosig4c++/biosig-dev.h.orig	2024-08-03 10:06:47 UTC
+++ biosig4c++/biosig-dev.h
@@ -35,6 +35,8 @@
 #include <time.h>
 #include "physicalunits.h"
 
+#include <sys/endian.h>
+#include <machine/endian.h> // for betoh16, etc.
 
 #ifdef __cplusplus
 extern "C" {
@@ -550,6 +552,12 @@ HDRTYPE* sopen_extended(const char* FileName, const ch
 #  include <endian.h>
 #  include <byteswap.h>
 
+#elif defined(__FreeBSD__) 
+#  include <machine/endian.h>
+#  define __BIG_ENDIAN _BIG_ENDIAN
+#  define __LITTLE_ENDIAN _LITTLE_ENDIAN
+#  define __BYTE_ORDER _BYTE_ORDER
+
 #elif defined(__FreeBSD__)
 #  include <machine/endian.h>
 
@@ -920,7 +928,7 @@ static inline void bef64a(  double i, void* r) {
 #ifndef INFINITY
 # define INFINITY (1.0/0.0)   /* positive infinity */
 #endif
-#ifndef isfinite
+#if 0
 # define isfinite(a) (-INFINITY < (a) && (a) < INFINITY)
 #endif
 
