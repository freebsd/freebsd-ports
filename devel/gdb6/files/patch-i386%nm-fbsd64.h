--- gdb/config/i386/nm-fbsd64.h.orig	Sat Mar 13 05:07:20 2004
+++ gdb/config/i386/nm-fbsd64.h	Wed May  5 11:20:14 2004
@@ -25,6 +25,9 @@
 /* Get generic BSD native definitions.  */
 #include "config/nm-bsd.h"
 
+/* Get generic FreeBSD native definitions.  */
+#include "config/nm-fbsd.h"
+
 /* Override child_pid_to_exec_file in 'inftarg.c'.  */
 #define CHILD_PID_TO_EXEC_FILE
 
