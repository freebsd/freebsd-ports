--- gdb/config/alpha/nm-fbsd.h	Tue Mar  6 00:21:21 2001
+++ gdb/config/alpha/nm-fbsd.h	Sun Oct 13 12:23:51 2002
@@ -22,6 +22,8 @@
 #ifndef NM_FBSD_H
 #define NM_FBSD_H
 
+#include "config/nm-fbsd.h"
+
 /* Type of the third argument to the `ptrace' system call.  */
 #define PTRACE_ARG3_TYPE caddr_t
 
