--- sj3/sj3.c.orig	Wed Jan 14 00:52:48 1998
+++ sj3/sj3.c	Fri Oct 25 10:51:35 2002
@@ -46,6 +46,9 @@
 #define LACKOF_SETLOCALE
 #endif
 #endif
+#if defined(__FreeBSD__)
+#include <sys/ioctl_compat.h>
+#endif
 #include <curses.h>
 #endif
 
@@ -1058,14 +1061,13 @@
            return;
         if (info.si_code == CLD_STOPPED)
 #else
-	union wait	status;
-	int		pid;
+	int		pid, status;
 
 /*
  * Remove warning.
  * Patched by Hidekazu Kuroki(hidekazu@cs.titech.ac.jp)		1996/8/10
  */
-	pid = wait3 ((int *)&status, (WNOHANG|WUNTRACED), 0);
+	pid = wait3 (&status, (WNOHANG|WUNTRACED), 0);
 	if (WIFSTOPPED (status))
 #endif
 		suspend();
