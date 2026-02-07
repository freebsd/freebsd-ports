--- src/System.h.orig	2004-05-13 22:02:43.000000000 +0800
+++ src/System.h	2013-07-30 00:13:30.000000000 +0800
@@ -20,30 +20,31 @@
 #ifndef VBA_SYSTEM_H
 #define VBA_SYSTEM_H
 
+#include <inttypes.h>
 #include "unzip.h"
 
 #ifndef NULL
 #define NULL 0
 #endif
 
-typedef unsigned char u8;
-typedef unsigned short u16;
-typedef unsigned int u32;
+typedef uint8_t u8;
+typedef uint16_t u16;
+typedef uint32_t u32;
 
 #ifdef _MSC_VER
 typedef unsigned __int64 u64;
 #else
-typedef unsigned long long u64;
+typedef uint64_t u64;
 #endif
 
-typedef signed char s8;
-typedef signed short s16;
-typedef signed int s32;
+typedef int8_t s8;
+typedef int16_t s16;
+typedef int32_t s32;
 
 #ifdef _MSC_VER
 typedef signed __int64 s64;
 #else
-typedef signed long long s64;
+typedef int64_t s64;
 #endif
 
 struct EmulatedSystem {
