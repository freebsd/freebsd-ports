
$FreeBSD$

--- src/libsoup/soup-private.h.orig	Tue Sep 18 00:56:04 2001
+++ src/libsoup/soup-private.h	Fri Sep 28 12:03:36 2001
@@ -20,6 +20,8 @@
 #include <config.h>
 #endif
 
+#include <sys/types.h>
+
 #ifdef HAVE_NETINET_IN_H
 #include <netinet/in.h>
 #endif
