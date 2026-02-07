--- types.h.orig	2000-08-04 20:19:23 UTC
+++ types.h
@@ -13,6 +13,8 @@
 #include MACH_TYPES
 #endif
 
+#include "endian.h"
+
 typedef unsigned char u8;
 typedef signed char s8;
 
