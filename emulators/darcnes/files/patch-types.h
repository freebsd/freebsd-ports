--- types.h.orig	Tue Dec  7 03:01:23 1999
+++ types.h	Thu Jun  1 02:43:11 2000
@@ -13,6 +13,8 @@
 #include MACH_TYPES
 #endif
 
+#include "endian.h"
+
 typedef unsigned char u8;
 typedef signed char s8;
 
