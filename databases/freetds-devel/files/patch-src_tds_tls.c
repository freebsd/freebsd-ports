--- src/tds/tls.c.orig	2015-05-10 16:53:53.649667739 +0600
+++ src/tds/tls.c	2015-05-10 17:04:29.479624026 +0600
@@ -46,6 +46,10 @@
 #include <sys/stat.h>
 #endif /* HAVE_SYS_STAT_H */
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <sys/socket.h>
+#endif
+
 #include <freetds/tds.h>
 #include <freetds/string.h>
 #include <freetds/tls.h>
