--- daemon/gvfswritechannel.c.orig	2007-12-22 18:50:10.000000000 -0500
+++ daemon/gvfswritechannel.c	2007-12-22 18:50:20.000000000 -0500
@@ -30,6 +30,7 @@
 #include <sys/un.h>
 #include <unistd.h>
 #include <fcntl.h>
+#include <string.h>
 
 #include <glib.h>
 #include <glib-object.h>
