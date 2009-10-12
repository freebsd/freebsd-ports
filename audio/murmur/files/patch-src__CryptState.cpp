--- src/CryptState.cpp.orig	2009-10-11 19:53:49.525380171 -0400
+++ src/CryptState.cpp	2009-10-11 19:54:36.401622290 -0400
@@ -187,7 +187,7 @@
 #define SHIFTBITS 63
 typedef quint64 subblock;
 
-#if __BYTE_ORDER == __BIG_ENDIAN
+#if Q_BYTE_ORDER == Q_BIG_ENDIAN
 #define SWAPPED(x) (x)
 #else
 #ifdef __x86_64__
