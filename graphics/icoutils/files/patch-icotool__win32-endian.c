--- icotool/win32-endian.c.orig	Sun Nov 27 18:43:33 2005
+++ icotool/win32-endian.c	Sun Nov 27 21:05:48 2005
@@ -17,6 +17,10 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
  */
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #include <config.h>
 #include "win32-endian.h"
 
@@ -27,6 +31,27 @@
 #define bswap_16(x) NXSwapShort(x)
 #define bswap_32(x) NXSwapInt(x)
 #define bswap_64(x) NXSwapLongLong(x)
+#elif defined(__FreeBSD__) && (__FreeBSD_version >= 470000)
+# include <sys/endian.h>
+# if (__FreeBSD_version >= 500000)
+#  define bswap_16(x) bswap16(x)
+#  define bswap_32(x) bswap32(x)
+#  define bswap_64(x) bswap64(x)
+# else
+#  define bswap_16(x) be16toh(x)
+#  define bswap_32(x) be32toh(x)
+#  define bswap_64(x) \
+    x = ((((x) & 0xff00000000000000) >> 56) | \
+        (((x) & 0x00ff000000000000) >> 40) | \
+        (((x) & 0x0000ff0000000000) >> 24) | \
+        (((x) & 0x000000ff00000000) >>  8) | \
+        (((x) & 0x00000000ff000000) <<  8) | \
+        (((x) & 0x0000000000ff0000) << 24) | \
+        (((x) & 0x000000000000ff00) << 40) | \
+        (((x) & 0x00000000000000ff) << 56))
+# endif /* >= 4.7-R || >= 5.0-CURRENT */
+#else
+# include "common/byteswap.h"
 #endif
 
 #define BSWAP16(x)  	((x) = bswap_16(x))
