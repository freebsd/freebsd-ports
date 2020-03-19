--- src/peerfile.c.orig	2020-02-09 21:48:57 UTC
+++ src/peerfile.c
@@ -4,6 +4,7 @@
 #include <string.h>
 #include <errno.h>
 #include <netdb.h>
+#include <sys/socket.h>
 
 #include "main.h"
 #include "conf.h"
