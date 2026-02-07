--- libDeployPkg/processPosix.c.orig	2023-07-18 17:10:48 UTC
+++ libDeployPkg/processPosix.c
@@ -28,6 +28,8 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/wait.h>
+#include <sys/types.h>
+#include <signal.h>
 #include <stdlib.h>
 
 #include "util.h"
