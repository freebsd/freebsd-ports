--- libDeployPkg/processPosix.c.orig	2017-02-24 22:15:37 UTC
+++ libDeployPkg/processPosix.c
@@ -28,6 +28,8 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/wait.h>
+#include <signal.h>
+#include <sys/types.h>
 
 #include "util.h"
 
