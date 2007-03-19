--- backend/ps/ps-interpreter.c.orig	Tue Mar 13 07:00:12 2007
+++ backend/ps/ps-interpreter.c	Tue Mar 13 07:00:21 2007
@@ -29,6 +29,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <sys/wait.h>
+#include <signal.h>
 #include <errno.h>
 
 #include "ps-interpreter.h"
