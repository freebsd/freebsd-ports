--- packet_handlers.c.ori	2006-08-18 16:37:02.000000000 +0200
+++ packet_handlers.c	2010-05-26 14:01:30.000000000 +0200
@@ -3,6 +3,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include "mysql_defines.h"
 #include "user_defines.h"
 #include "state_map.h"
