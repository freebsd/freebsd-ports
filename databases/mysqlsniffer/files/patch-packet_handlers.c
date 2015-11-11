--- packet_handlers.c.orig	2006-08-18 14:37:02 UTC
+++ packet_handlers.c
@@ -3,6 +3,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include "mysql_defines.h"
 #include "user_defines.h"
 #include "state_map.h"
