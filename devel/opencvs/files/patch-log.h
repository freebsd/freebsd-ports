--- log.h.orig	2008-06-09 18:00:34.000000000 -0700
+++ log.h	2011-04-18 23:44:44.000000000 -0700
@@ -29,6 +29,9 @@
 
 #include <stdarg.h>
 
+/* For building on FreeBSD */
+#define	__dead
+
 /* log priority levels */
 #define LP_NOTICE	0
 #define LP_ERR		1
