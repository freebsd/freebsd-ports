--- src/s/freebsd.h.old	Sat Dec 25 16:06:34 2004
+++ src/s/freebsd.h	Sat Dec 25 16:07:10 2004
@@ -29,7 +29,7 @@
 #ifndef __FreeBSD_version
 #include <osreldate.h>
 #endif
-#if __FreeBSD_version >= 199701
+#if __FreeBSD_version >= 199701 && __FreeBSD_version < 600006
 #define LIBS_SYSTEM "-lutil -lxpg4"
 #else
 #define LIBS_SYSTEM "-lutil"
