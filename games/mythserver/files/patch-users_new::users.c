--- users_new/users.c.orig	Wed Jan  7 17:15:33 2004
+++ users_new/users.c	Wed Jan  7 17:15:41 2004
@@ -4,6 +4,10 @@
 Refer to the file "License.txt" for details
 */
 
+#include <unistd.h>
+#include <fcntl.h>
+#include <string.h>
+
 #include "cseries.h"
 #include "environment.h"
 #include "metaserver_common_structs.h"
@@ -13,10 +17,6 @@
 #include "byte_swapping.h"
 #include "bungie_net_player.h"
 #include "users.h"
-
-#include <unistd.h>
-#include <fcntl.h>
-#include <string.h>
 
 #define	BUNGIE_NET_USER_DB_SIGNATURE		'PLAY'
 
