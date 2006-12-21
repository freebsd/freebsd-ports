--- pskmodem/measpsk.c.orig	Tue Sep 19 17:51:37 2006
+++ pskmodem/measpsk.c	Tue Sep 19 17:52:15 2006
@@ -32,6 +32,8 @@
 #ifdef HAVE_STROPTS_H
 #include <stropts.h>
 #endif
+#include <sys/param.h>
+#include <sys/types.h>
 #ifdef HAVE_SYS_CONF_H
 #include <sys/conf.h>
 #endif
