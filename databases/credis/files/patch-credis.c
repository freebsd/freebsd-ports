--- credis.c.orig	2011-02-02 09:38:06.000000000 -0500
+++ credis.c	2011-02-02 09:38:37.000000000 -0500
@@ -34,6 +34,9 @@
 #define WIN32_LEAN_AND_MEAN
 #include <winsock2.h>
 #else 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 #include <arpa/inet.h>
 #include <errno.h>
 #include <fcntl.h>
