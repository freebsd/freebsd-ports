--- src/get_cmd_out.c.orig	Sun Jun  5 22:09:21 2005
+++ src/get_cmd_out.c	Sun Jun  5 22:09:38 2005
@@ -11,6 +11,7 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <errno.h>
+#include <signal.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include "util.h"
