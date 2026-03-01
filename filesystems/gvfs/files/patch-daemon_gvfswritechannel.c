--- daemon/gvfswritechannel.c.orig	2024-10-18 10:28:21 UTC
+++ daemon/gvfswritechannel.c
@@ -29,6 +29,7 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <fcntl.h>
+#include <string.h>
 
 #include <glib.h>
 #include <glib-object.h>
