--- common/network.c.orig	Fri Jan 21 16:55:52 2005
+++ common/network.c	Fri Jan 21 16:56:18 2005
@@ -29,6 +29,7 @@
 #include <netdb.h>
 #include <errno.h>
 #include <string.h>
+#include <netinet/in.h>
 
 #include "config.h"
 #include "driver.h"
