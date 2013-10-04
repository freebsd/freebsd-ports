--- mupen64plus-video-glide64/src/Util.h	2013-10-04 03:39:06.000000000 -0500
+++ mupen64plus-video-glide64/src/Util.h	2013-10-04 03:43:01.000000000 -0500
@@ -37,6 +37,8 @@
 #ifndef Util_H
 #define Util_H
 
+#include <stdint.h>
+
 #include "winlnxdefs.h"
 #include "rdp.h"
 
@@ -91,5 +93,17 @@
             lx = lc; \
         }
 
-#endif  // ifndef Util_H
+#if defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))
+  #include <stdlib.h>
+  #define bswap32(x) _byteswap_ulong(x)
+#else
+static inline uint32_t bswap32(uint32_t val)
+{
+        return (((val & 0xff000000) >> 24) |
+                ((val & 0x00ff0000) >>  8) |
+                ((val & 0x0000ff00) <<  8) |
+                ((val & 0x000000ff) << 24));
+}
+#endif
 
+#endif  // ifndef Util_H
