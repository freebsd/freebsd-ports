--- plot.c.orig	Sat Mar 14 23:22:20 1992
+++ plot.c	Sun Jan 21 21:06:06 2007
@@ -10,16 +10,31 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #include <math.h>
 #include "screen.h"
 
-extern char *strcpy();
+static plt_select_fields();
+static plt_turn_off();
+static plt_turn_on();
+static plt_file();
+static plot_cartesian(FILE *pfp);
+static plot_polar(FILE *pfp);
+
+#if (defined(__unix__) || defined(unix)) && !defined(USG)             
+#include <sys/param.h>                                                
+#endif
+
+#if defined(VMS) || defined(unix)
+#include <errno.h>
+#endif
 
 #ifdef VMS
 #include <perror.h>
-#include <errno.h>
 #else
+#ifndef BSD
 extern char *sys_errlist[];
+#endif
 extern errno;
 #endif
 
