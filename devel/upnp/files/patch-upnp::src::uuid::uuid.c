--- upnp/src/uuid/uuid.c.orig	Sun Apr  6 02:30:20 2003
+++ upnp/src/uuid/uuid.c	Sun Apr  6 02:30:41 2003
@@ -21,6 +21,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include "sysdep.h"
 #include "uuid.h"
