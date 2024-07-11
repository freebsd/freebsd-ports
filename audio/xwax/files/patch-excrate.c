--- excrate.c.orig	2024-06-25 01:52:31 UTC
+++ excrate.c
@@ -28,6 +28,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/signal.h>
 #include <sys/wait.h>
 
 #include "debug.h"
