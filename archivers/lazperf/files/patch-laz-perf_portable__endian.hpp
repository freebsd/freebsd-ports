--- laz-perf/portable_endian.hpp.orig	2018-07-12 13:01:41 UTC
+++ laz-perf/portable_endian.hpp
@@ -43,11 +43,11 @@
 #   define __PDP_ENDIAN    PDP_ENDIAN
 **/
 
-#elif defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__)
 
 #   include <sys/endian.h>
 
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#elif defined(__NetBSD__) || defined(__DragonFly__)
 
 #   define be16toh betoh16
 #   define le16toh letoh16
