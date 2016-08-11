--- src/codec.c.orig	2016-05-15 00:38:52 UTC
+++ src/codec.c
@@ -21,6 +21,9 @@
 #  if defined(__APPLE__)
 #    include <libkern/OSByteOrder.h>
 #    define __bswap_32 OSSwapInt32
+#  elif defined(__FreeBSD__)
+#    include <sys/endian.h>
+#    define __bswap_32 bswap32
 #  else
 #    include <byteswap.h>
 #  endif
