--- process_env.c.orig	Fri Jun 10 10:10:07 2005
+++ process_env.c	Fri Jun 10 10:10:31 2005
@@ -14,6 +14,10 @@
 #include <sys/param.h>
 #endif
 
+#ifdef FREEBSD
+#include <unistd.h>
+#endif
+
 #include "globals.h"
 #include "sys.h"
 #include "run_time.h"
