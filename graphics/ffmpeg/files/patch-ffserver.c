--- ffserver.c.orig	Tue Oct  8 13:45:36 2002
+++ ffserver.c	Tue Oct  8 13:46:10 2002
@@ -20,7 +20,6 @@
 #include "avformat.h"
 
 #include <stdarg.h>
-#include <netinet/in.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
@@ -30,6 +29,7 @@
 #include <time.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <sys/wait.h>
 #include <arpa/inet.h>
 #include <netdb.h>
