--- src/alutInternal.h.orig	Fri Mar 31 06:15:08 2006
+++ src/alutInternal.h	Fri Mar 31 06:15:46 2006
@@ -13,23 +13,8 @@
 
 #if HAVE_STDINT_H
 #include <stdint.h>
-#elif _MSC_VER < 1300
-typedef char int8_t;
-typedef unsigned char uint8_t;
-typedef short int16_t;
-typedef unsigned short uint16_t;
-typedef int int32_t;
-typedef unsigned int uint32_t;
-#elif HAVE_BASETSD_H
-#include <basetsd.h>
-typedef INT8 int8_t;
-typedef UINT8 uint8_t;
-typedef INT16 int16_t;
-typedef UINT16 uint16_t;
-typedef INT32 int32_t;
-typedef UINT32 uint32_t;
 #else
-#error Do not know sized types on this platform
+#include <inttypes.h>
 #endif
 
 typedef uint16_t UInt16LittleEndian;
