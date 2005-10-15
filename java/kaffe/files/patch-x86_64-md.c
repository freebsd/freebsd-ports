--- config/x86_64/freebsd2/md.c.orig	Sat Oct 15 13:49:14 2005
+++ config/x86_64/freebsd2/md.c		Sat Oct 15 13:50:23 2005
@@ -13,6 +13,10 @@
 #include "config.h"
 #include "config-std.h"
 
+#if defined(HAVE_SYS_TYPES_H)
+#include <sys/types.h>
+#endif
+
 #if defined(HAVE_SYS_SYSCTL_H)
 #include <sys/sysctl.h>
 
