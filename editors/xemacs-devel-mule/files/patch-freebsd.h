--- src/s/freebsd.h.old	Sun Dec 26 00:47:51 2004
+++ src/s/freebsd.h	Sun Dec 26 00:48:27 2004
@@ -29,7 +29,7 @@
 #ifndef __FreeBSD_version
 #include <osreldate.h>
 #endif
-#if __FreeBSD_version >= 199701
+#if __FreeBSD_version >= 199701 && __FreeBSD_version < 600006
 #define LIBS_SYSTEM "-lutil -lxpg4"
 #else
 #define LIBS_SYSTEM "-lutil"
