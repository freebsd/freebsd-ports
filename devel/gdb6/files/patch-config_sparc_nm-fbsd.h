--- gdb/config/sparc/nm-fbsd.h.orig	Sat Mar 13 05:07:20 2004
+++ gdb/config/sparc/nm-fbsd.h	Sat Apr 10 01:06:19 2004
@@ -24,9 +24,30 @@
 
 /* Get generic BSD native definitions.  */
 #include "config/nm-bsd.h"
+/* Get generic FreeBSD native definitions.  */
+#include "config/nm-fbsd.h"
 
 /* Shared library support.  */
 
 #include "solib.h"
+
+/* Override child_pid_to_exec_file in 'inftarg.c'.  */
+#define CHILD_PID_TO_EXEC_FILE
+
+/* FreeBSD has a /proc.  */
+#define USE_PROC_FS
+
+/*	DEO:XXX where did the rest of this file go vs 6.0.0.90 ??	*/
+
+/* Solaris compatability.  */
+#define R_PC		r_pc
+#define R_nPC		r_npc
+#define R_Y		r_y
+#define R_I7		/* ?? */
+#define pr_fr		fpu_fr
+#define pr_fsr		fpu_fsr
+#define regp		/* ?? */
+#if 0
+#endif
 
 #endif /* nm-fbsd.h */
