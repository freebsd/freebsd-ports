--- source/zita-alsa-pcmi.cc.orig	2022-07-14 07:07:32 UTC
+++ source/zita-alsa-pcmi.cc
@@ -18,9 +18,16 @@
 // ----------------------------------------------------------------------------
 
 
+#if defined(__FreeBSD__)
+#  include <machine/endian.h>
+#  define bswap_32(x) bswap32(x)
+#else
 #include <endian.h>
+#endif
 #include <stdint.h>
+#if !defined(__FreeBSD__)
 #include <byteswap.h>
+#endif
 #include <sys/time.h>
 #include "zita-alsa-pcmi.h"
 
