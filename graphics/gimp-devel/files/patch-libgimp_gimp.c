--- libgimp/gimp.c.orig	Fri Jun  2 08:04:39 2006
+++ libgimp/gimp.c	Fri Jun  9 11:24:56 2006
@@ -21,7 +21,7 @@
 
 #include "config.h"
 
-#define _POSIX_SOURCE  /* all the sigaction stuff is POSIX */
+#define __XSI_VISIBLE  /* all the sigaction stuff is POSIX */
 #define _SVID_SOURCE   /* except for SA_RESTART, it seems  */
 
 #include <errno.h>
@@ -30,6 +30,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
+#include <floatingpoint.h>
 
 #ifdef HAVE_SYS_TIME_H
 #include <sys/time.h>
@@ -292,6 +293,9 @@
   gimp_env_init (TRUE);
 
   progname = argv[0];
+
+  /* Ignore floating point exceptions */
+  fpsetmask(0);
 
   basename = g_path_get_basename (progname);
 
