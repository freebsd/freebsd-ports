--- src/netbuf.h.orig	Wed Oct  1 13:17:13 2003
+++ src/netbuf.h	Mon Mar 22 10:47:07 2004
@@ -37,7 +37,7 @@
 #ifndef G_NETBUF_H
 #define G_NETBUF_H
 
-#include <stdint.h>
+#include <sys/types.h>
 
 typedef struct _slist_t{
 	void		*data;
