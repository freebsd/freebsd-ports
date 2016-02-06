--- log.h.orig	2008-06-10 03:00:34.000000000 +0200
+++ log.h	2016-02-06 23:33:35.531120000 +0100
@@ -29,6 +29,9 @@
 
 #include <stdarg.h>
 
+/* For building on FreeBSD */
+#define	__dead
+
 /* log priority levels */
 #define LP_NOTICE	0
 #define LP_ERR		1
