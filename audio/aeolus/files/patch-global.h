--- global.h.orig	2022-05-05 04:18:20 UTC
+++ global.h
@@ -21,14 +21,14 @@
 #ifndef __GLOBAL_H
 #define __GLOBAL_H
 
-#include <endian.h>
-#ifdef __BYTE_ORDER
-#if (__BYTE_ORDER == __LITTLE_ENDIAN)
+#include <sys/endian.h>
+#ifdef _BYTE_ORDER
+#if (_BYTE_ORDER == _LITTLE_ENDIAN)
 #define WR2(p,v) { (p)[0] = v; (p)[1] = v >> 8; }
 #define WR4(p,v) { (p)[0] = v; (p)[1] = v >> 8;  (p)[2] = v >> 16;  (p)[3] = v >> 24; }
 #define RD2(p) ((p)[0] + ((p)[1] << 8));
 #define RD4(p) ((p)[0] + ((p)[1] << 8) + ((p)[2] << 16) + ((p)[3] << 24));
-#elif (__BYTE_ORDER == __BIG_ENDIAN)
+#elif (_BYTE_ORDER == _BIG_ENDIAN)
 #define WR2(p,v) { (p)[1] = v; (p)[0] = v >> 8; }
 #define WR4(p,v) { (p)[3] = v; (p)[2] = v >> 8;  (p)[1] = v >> 16;  (p)[0] = v >> 24; }
 #define RD2(p) ((p)[1] + ((p)[0] << 8));
