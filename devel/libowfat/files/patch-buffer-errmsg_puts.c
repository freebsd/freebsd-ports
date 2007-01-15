--- buffer/errmsg_puts.c.orig	Sat Jan 13 15:03:22 2007
+++ buffer/errmsg_puts.c	Sat Jan 13 15:04:23 2007
@@ -13,7 +13,9 @@
 }
 
 #else
+#include <sys/types.h>
 #include <sys/uio.h>
+#include <unistd.h>
 
 enum { COUNT=25 };
 static struct iovec x[COUNT];
