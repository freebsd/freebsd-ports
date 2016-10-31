--- common_d/appenv.h.orig	2016-10-14 17:17:56.243169000 -0400
+++ common_d/appenv.h	2016-10-14 17:30:46.674743000 -0400
@@ -358,7 +358,8 @@
     defined(__alpha) || defined(__alpha__) || \
     defined(vax) || defined(__vax__) || \
     (defined(MIPSEL) || defined(__MIPSEL__) || \
-     defined(__MIPSEL) || defined(_MIPSEL))
+     defined(__MIPSEL) || defined(_MIPSEL)) || \
+    (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__))
 #define _BYTE_ORDER_	_L_ENDIAN_
 #else
 #define _BYTE_ORDER_	_B_ENDIAN_
