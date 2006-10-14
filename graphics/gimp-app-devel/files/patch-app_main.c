--- app/main.c.orig	Fri Jun  9 12:02:54 2006
+++ app/main.c	Fri Jun  9 12:03:28 2006
@@ -18,7 +18,7 @@
 
 #include "config.h"
 
-#define _POSIX_SOURCE  /* all the sigaction stuff is POSIX */
+#define __XSI_VISIBLE
 #define _SVID_SOURCE   /* except for SA_RESTART, it seems  */
 
 #include <stdio.h>
