--- common/unicode/platform.h.orig	2016-03-23 20:49:58 UTC
+++ common/unicode/platform.h
@@ -379,8 +379,8 @@
  */
 #ifdef U_IS_BIG_ENDIAN
     /* Use the predefined value. */
-#elif defined(BYTE_ORDER) && defined(BIG_ENDIAN)
-#   define U_IS_BIG_ENDIAN (BYTE_ORDER == BIG_ENDIAN)
+#elif defined(_BYTE_ORDER) && defined(_BIG_ENDIAN)
+#   define U_IS_BIG_ENDIAN (_BYTE_ORDER == _BIG_ENDIAN)
 #elif defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__)
     /* gcc */
 #   define U_IS_BIG_ENDIAN (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
