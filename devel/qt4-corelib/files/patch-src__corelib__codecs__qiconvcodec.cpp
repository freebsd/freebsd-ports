--- ./src/corelib/codecs/qiconvcodec.cpp.orig	2009-06-20 08:57:57.000000000 +0400
+++ ./src/corelib/codecs/qiconvcodec.cpp	2009-07-01 23:12:06.000000000 +0400
@@ -62,7 +62,7 @@
 #elif defined(Q_OS_AIX)
 #  define NO_BOM
 #  define UTF16 "UCS-2"
-#elif defined(Q_OS_MAC)
+#elif defined(Q_OS_MAC) || defined(Q_OS_FREEBSD)
 #  define NO_BOM
 #  if Q_BYTE_ORDER == Q_BIG_ENDIAN
 #    define UTF16 "UTF-16BE"
