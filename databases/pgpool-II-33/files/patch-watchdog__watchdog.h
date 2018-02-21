--- watchdog/watchdog.h.orig	2018-02-13 05:20:52 UTC
+++ watchdog/watchdog.h
@@ -56,6 +56,28 @@
 #define WD_TIME_DIFF_SEC(a,b) (int)(((a).tv_sec - (b).tv_sec) + \
                                     ((a).tv_usec - (b).tv_usec) / 1000000.0)
 
+/* For valid x, exactly one of WIFSIGNALED(x), WIFEXITED(x), WIFSTOPPED(x) is true.  */
+#ifndef WIFSIGNALED
+# define WIFSIGNALED(x) (WTERMSIG (x) != 0 && WTERMSIG(x) != 0x7f)
+#endif
+#ifndef WIFEXITED
+# define WIFEXITED(x) (WTERMSIG (x) == 0)
+#endif
+#ifndef WIFSTOPPED
+# define WIFSTOPPED(x) (WTERMSIG (x) == 0x7f)
+#endif
+
+/* The termination signal. Only to be accessed if WIFSIGNALED(x) is true.  */
+#ifndef WTERMSIG
+# define WTERMSIG(x) ((x) & 0x7f)
+#endif
+
+
+/* The exit status. Only to be accessed if WIFEXITED(x) is true.  */
+#ifndef WEXITSTATUS
+# define WEXITSTATUS(x) (((x) >> 8) & 0xff)
+#endif
+
 /*
  * packet number of watchdog negotiation
  */
