--- include/astrometry/an-endian.h.orig	2015-12-12 19:02:27 UTC
+++ include/astrometry/an-endian.h
@@ -11,7 +11,7 @@
 // (actually 10.5 does)
 #if __APPLE__
 # include <sys/types.h>
-#elif __FreeBSD__
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 # include <sys/endian.h>
 #elif __sun
 # include <sys/isa_defs.h>
