--- DisplayOutput/LoadPNG.cpp.orig	2018-06-21 01:42:42 UTC
+++ DisplayOutput/LoadPNG.cpp
@@ -5,7 +5,7 @@
 #include	"png.h"
 
 #ifdef LINUX_GNU
-#include <endian.h>
+#include <sys/endian.h>
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #define __LITTLE_ENDIAN__ __LITTLE_ENDIAN
 #undef __BIG_ENDIAN__
