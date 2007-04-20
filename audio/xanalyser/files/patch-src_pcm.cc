--- src/pcm.cc.orig	Mon Apr 16 17:16:58 2007
+++ src/pcm.cc	Mon Apr 16 17:26:52 2007
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
