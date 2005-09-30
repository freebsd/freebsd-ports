--- drivers/festival/festivalsynthesisdriver.c.orig	Thu Sep 29 23:19:28 2005
+++ drivers/festival/festivalsynthesisdriver.c	Thu Sep 29 23:19:41 2005
@@ -32,6 +32,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <libbonobo.h>
 #include <netdb.h>
 #include "festivalsynthesisdriver.h"
