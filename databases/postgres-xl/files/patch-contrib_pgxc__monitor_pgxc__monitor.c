--- contrib/pgxc_monitor/pgxc_monitor.c.orig	2017-04-19 15:17:02 UTC
+++ contrib/pgxc_monitor/pgxc_monitor.c
@@ -49,6 +49,7 @@
 
 #include <stdlib.h>
 #include <getopt.h>
+#include <sys/wait.h>
 
 /* Define all the node types */
 typedef enum
