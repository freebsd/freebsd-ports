--- room_new/roomd_new.c.orig	Wed Jan  7 17:11:07 2004
+++ room_new/roomd_new.c	Wed Jan  7 17:11:17 2004
@@ -4,7 +4,6 @@
 Refer to the file "License.txt" for details
 */
 
-#include "cseries.h"
 #include <string.h>
 #include <fcntl.h>
 #include <sys/types.h>
@@ -20,6 +19,7 @@
 #include <errno.h>
 #include <signal.h>
 
+#include "cseries.h"
 #include "environment.h"
 #include "metaserver_common_structs.h"
 #include "stats.h"
