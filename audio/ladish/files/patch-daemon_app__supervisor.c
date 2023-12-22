--- daemon/app_supervisor.c.orig	2023-12-18 22:40:21 UTC
+++ daemon/app_supervisor.c
@@ -30,6 +30,7 @@
 #include <sys/stat.h>
 #include <signal.h>
 #include <unistd.h>
+#include <sys/wait.h>
 
 #include "app_supervisor.h"
 #include "../dbus_constants.h"
