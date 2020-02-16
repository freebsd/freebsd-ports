--- backend/pixma/pixma_bjnp.c.orig	2020-02-03 09:33:57 UTC
+++ backend/pixma/pixma_bjnp.c
@@ -72,6 +72,7 @@
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
+#include <sys/param.h>
 
 /*
  * networking stuff
@@ -1990,8 +1991,8 @@ sanei_bjnp_find_devices (const char **conf_devices,
   fd_set fdset;
   fd_set active_fdset;
   struct timeval timeout;
-  char scanner_host[HOST_NAME_MAX];
-  char uri[HOST_NAME_MAX + 32];
+  char scanner_host[MAXHOSTNAMELEN];
+  char uri[MAXHOSTNAMELEN + 32];
   int dev_no;
   int port;
   int auto_detect = 1;
