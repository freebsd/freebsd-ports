--- bonobo-activation/bonobo-activation-init.c.orig	Sat Jun 14 02:09:52 2003
+++ bonobo-activation/bonobo-activation-init.c	Sat Jun 14 02:10:13 2003
@@ -34,6 +34,7 @@
 #include "bonobo-activation-private.h"
 #include "bonobo-activation-register.h"
 #include "bonobo-activation-version.h"
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <fcntl.h>
@@ -44,7 +45,6 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/socket.h>
-#include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>
 
