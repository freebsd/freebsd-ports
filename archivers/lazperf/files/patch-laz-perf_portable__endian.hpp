--- laz-perf/portable_endian.hpp.orig	2017-08-16 21:27:03 UTC
+++ laz-perf/portable_endian.hpp
@@ -41,11 +41,11 @@
 #   define __PDP_ENDIAN    PDP_ENDIAN
 **/
 
-#elif defined(__OpenBSD__) || defined(EMSCRIPTEN_OPEN_BSD)
+#elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(EMSCRIPTEN_OPEN_BSD)
 
 #   include <sys/endian.h>
 
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(EMSCRIPTEN_BSD)
+#elif defined(__NetBSD__) || defined(__DragonFly__) || defined(EMSCRIPTEN_BSD)
 
 #   include <sys/endian.h>
 
