--- src/s/freebsd.h.orig	Sun Nov 21 16:14:32 2004
+++ src/s/freebsd.h	Sun Nov 21 16:15:10 2004
@@ -29,7 +29,7 @@
 #ifndef __FreeBSD_version
 #include <osreldate.h>
 #endif
-#if __FreeBSD_version >= 199701
+#if __FreeBSD_version >= 199701 && __FreeBSD_version < 600006
 #define LIBS_SYSTEM "-lutil -lxpg4"
 #else
 #define LIBS_SYSTEM "-lutil"
