--- mpiosh/callback.c.orig     Thu Jun 19 19:51:43 2003
+++ mpiosh/callback.c  Thu Jun 19 19:52:29 2003
@@ -29,11 +29,14 @@
 #include <regex.h>
 #include <time.h>
 #include <unistd.h>
+#include <limits.h>

 #include "mpiosh.h"
 #include "command.h"

 #include "libmpio/debug.h"
+
+#define NAME_MAX      PATH_MAX

 /* commands */
 void
