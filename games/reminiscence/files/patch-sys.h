--- sys.h.orig	2007-03-17 00:45:52.000000000 +0300
+++ sys.h	2010-02-02 20:23:49.000000000 +0300
@@ -19,12 +19,14 @@
 #ifndef __SYS_H__
 #define __SYS_H__
 
-typedef unsigned char uint8;
-typedef signed char int8;
-typedef unsigned short uint16;
-typedef signed short int16;
-typedef unsigned long uint32;
-typedef signed long int32;
+#include <stdint.h>
+
+typedef uint8_t uint8;
+typedef int8_t int8;
+typedef uint16_t uint16;
+typedef int16_t int16;
+typedef uint32_t uint32;
+typedef int32_t int32;
 
 inline uint16 READ_BE_UINT16(const void *ptr) {
 	const uint8 *b = (const uint8 *)ptr;
