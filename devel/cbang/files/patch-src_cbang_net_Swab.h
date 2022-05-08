--- src/cbang/net/Swab.h.orig	2021-08-10 22:46:49 UTC
+++ src/cbang/net/Swab.h
@@ -42,7 +42,10 @@
 #elif __APPLE__
 #include <machine/endian.h>
 
-#else // POSIX systems
+#elif __FreeBSD__
+#include <sys/endian.h>
+
+#else // other POSIX systems
 #include <endian.h>
 #endif
 
