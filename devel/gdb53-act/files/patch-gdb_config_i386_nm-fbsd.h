--- gdb/config/i386/nm-fbsd.h	Fri Jun 28 11:44:49 2002
+++ gdb/config/i386/nm-fbsd.h	Sun Oct 13 10:53:27 2002
@@ -26,6 +26,7 @@
 #define I386_USE_GENERIC_WATCHPOINTS
 #endif
 
+#include "config/nm-fbsd.h"
 #include "i386/nm-i386.h"
 
 #ifdef HAVE_SYS_PARAM_H
