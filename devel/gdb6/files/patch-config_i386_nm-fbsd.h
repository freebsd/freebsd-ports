--- gdb/config/i386/nm-fbsd.h.orig	Fri Jun 28 11:44:49 2002
+++ gdb/config/i386/nm-fbsd.h	Sun Jan 18 20:50:33 2004
@@ -26,6 +26,9 @@
 #define I386_USE_GENERIC_WATCHPOINTS
 #endif
 
+/* Get generic FreeBSD native definitions.  */
+#include "config/nm-fbsd.h"
+
 #include "i386/nm-i386.h"
 
 #ifdef HAVE_SYS_PARAM_H
