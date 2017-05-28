--- src/system/ByteOrder.hxx.orig      2017-05-26 09:10:52 UTC
+++ src/system/ByteOrder.hxx
@@ -34,7 +34,15 @@

 #include <stdint.h>

-#if defined(__i386__) || defined(__x86_64__) || defined(__ARMEL__)
+#if defined(__BYTE_ORDER__)
+#  if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
+#    define IS_LITTLE_ENDIAN true
+#    define IS_BIG_ENDIAN false
+#  else
+#    define IS_LITTLE_ENDIAN false
+#    define IS_BIG_ENDIAN true
+#  endif
+#elif defined(__i386__) || defined(__x86_64__) || defined(__ARMEL__)
 /* well-known little-endian */
 #  define IS_LITTLE_ENDIAN true
 #  define IS_BIG_ENDIAN false
