--- src/pcPTY.c.orig	2003-02-17 20:30:10.000000000 -0500
+++ src/pcPTY.c	2011-08-03 19:07:17.000000000 -0400
@@ -21,8 +21,8 @@
 # include <libutil.h>
 #else
 # include <pty.h>	/* openpty() */
+# include <utmp.h>	/* login_tty() */
 #endif
-#include <utmp.h>	/* login_tty() */
 
 #include "pcMain.h"
 
