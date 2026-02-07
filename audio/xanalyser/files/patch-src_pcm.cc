--- src/pcm.cc.orig	2007-03-15 18:22:14 UTC
+++ src/pcm.cc
@@ -11,6 +11,9 @@
 #  include <machine/byte_swap.h>
 #elif __FreeBSD__
 #  include <sys/endian.h>
+#  define	__BYTE_ORDER	_BYTE_ORDER
+#  define	__LITTLE_ENDIAN	_LITTLE_ENDIAN
+#  define	__BIG_ENDIAN	_BIG_ENDIAN
 #else
 #  include <byteswap.h>
 #endif
