--- gdb/config/alpha/nm-fbsd.h.orig	Sat Mar 13 05:07:19 2004
+++ gdb/config/alpha/nm-fbsd.h	Sat Apr 10 00:49:21 2004
@@ -25,6 +25,7 @@
 
 /* Get generic BSD native definitions.  */
 #include "config/nm-bsd.h"
+#include "config/nm-fbsd.h"
 
 /* The Alpha does not step over a breakpoint.  */
 #define CANNOT_STEP_BREAKPOINT 1
