--- src/get_cmd_out.c.orig  Sun May  9 16:29:56 2004
+++ src/get_cmd_out.c       Sun May  9 16:30:55 2004
@@ -12,6 +12,7 @@
 #include <unistd.h>
 #include <errno.h>
 #include <sys/types.h>
+#include <signal.h>
 #include <sys/wait.h>
 #include "util.h"
