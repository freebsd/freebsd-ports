--- cddb-slave2/gnet-private.h.orig	Tue Aug 31 19:58:18 2004
+++ cddb-slave2/gnet-private.h	Tue Aug 31 20:02:23 2004
@@ -68,7 +68,7 @@
 #include <resolv.h>
 #include <netdb.h>
 
-#ifndef __socklen_t_defined
+#if !defined(__socklen_t_defined) && !defined(__FreeBSD__)
 typedef guint32 socklen_t;
 #endif
 
