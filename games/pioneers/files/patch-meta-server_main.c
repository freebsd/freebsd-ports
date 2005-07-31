--- meta-server/main.c.orig	Fri Jul 22 17:08:33 2005
+++ meta-server/main.c	Fri Jul 22 17:10:56 2005
@@ -29,9 +29,11 @@
 #ifdef HAVE_GETOPT_H
 #include <getopt.h>
 #endif
+#include <netinet/in.h>
 #include <fcntl.h>
 #include <syslog.h>
 #include <sys/wait.h>
+#include <sys/socket.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <netdb.h>
