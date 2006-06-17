--- upnp/src/uuid/uuid.c.orig	Sat Jun 17 12:16:38 2006
+++ upnp/src/uuid/uuid.c	Sat Jun 17 12:16:52 2006
@@ -22,6 +22,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include "sysdep.h"
 #include "uuid.h"
