--- source/zita-alsa-pcmi.cc.orig	2021-11-26 09:24:45 UTC
+++ source/zita-alsa-pcmi.cc
@@ -18,9 +18,17 @@
 // ----------------------------------------------------------------------------
 
 
+#if defined(__FreeBSD__)
+#include <machine/endian.h>
+#else
 #include <endian.h>
+#endif
 #include <stdint.h>
+#if defined(__FreeBSD__)
+#include <infiniband/byteswap.h>
+#else
 #include <byteswap.h>
+#endif
 #include <sys/time.h>
 #include "zita-alsa-pcmi.h"
 
@@ -983,7 +991,7 @@ char *Alsa_pcmi::play_floatre (const float *src, char 
     while (nfrm--)
     {
         d = *src;
-        *((float *) dst) = __bswap_32 (d);
+        *((float *) dst) = bswap_32 (d);
         dst += _play_step;
         src += step;
     }  
@@ -1105,7 +1113,7 @@ const char *Alsa_pcmi::capt_floatre (const char *src, 
     while (nfrm--)
     {
         d = *((float *) src);
-        *dst = __bswap_32 (d);
+        *dst = bswap_32 (d);
         dst += step;
         src += _capt_step;
     }  
