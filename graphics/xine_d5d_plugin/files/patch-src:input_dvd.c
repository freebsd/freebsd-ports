--- src/input_dvd.c.orig	Thu May  2 06:35:36 2002
+++ src/input_dvd.c	Sun Jun  2 04:17:03 2002
@@ -33,7 +33,6 @@
 #include <string.h>
 #include <errno.h>
 
-#include <sys/mount.h>
 #include <sys/wait.h>
 
 #include <sys/poll.h>
@@ -906,7 +905,7 @@
   dvdnav_input_plugin_t *this;
   config_values_t *config = xine->config;
 
-  if (iface != 6) {
+  if (iface != 7) {
     printf("d5d input plugin doesn't support plugin API version %d.\n"
 	   "PLUGIN DISABLED.\n"
 	   "This means there's a version mismatch between xine and this input"
