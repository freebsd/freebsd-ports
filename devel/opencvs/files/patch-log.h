--- log.h.orig	2008-06-10 01:00:34 UTC
+++ log.h
@@ -29,6 +29,9 @@
 
 #include <stdarg.h>
 
+/* For building on FreeBSD */
+#define	__dead
+
 /* log priority levels */
 #define LP_NOTICE	0
 #define LP_ERR		1
