--- ./ext/posix/posix.c.orig	2013-09-09 09:15:14.000000000 +0200
+++ ./ext/posix/posix.c	2014-01-10 15:21:47.831554392 +0100
@@ -68,6 +68,10 @@
 #include "lauxlib.h"
 #include "lua52compat.h"
 
+#ifdef __FreeBSD__
+#define	O_DSYNC	O_SYNC
+#endif
+
 #ifndef STREQ
 #  define STREQ(a, b)     (strcmp (a, b) == 0)
 #endif
