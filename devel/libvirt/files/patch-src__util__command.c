--- ./src/util/command.c.orig	2011-05-13 09:51:42.000000000 -0700
+++ ./src/util/command.c	2011-05-13 09:52:12.000000000 -0700
@@ -22,9 +22,11 @@
 #include <config.h>
 
 #include <poll.h>
+#include <signal.h>
 #include <stdarg.h>
 #include <stdlib.h>
 #include <sys/stat.h>
+#include <sys/types.h>
 #include <sys/wait.h>
 
 #include "command.h"
