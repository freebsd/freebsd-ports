--- users_new/orders.c.orig	Wed Jan  7 17:14:38 2004
+++ users_new/orders.c	Wed Jan  7 17:14:50 2004
@@ -4,6 +4,10 @@
 Refer to the file "License.txt" for details
 */
 
+#include <unistd.h>
+#include <fcntl.h>
+#include <time.h>
+
 #include "cseries.h"
 #include "environment.h"
 #include "metaserver_common_structs.h"
@@ -12,10 +16,6 @@
 #include "bungie_net_player.h"
 #include "bungie_net_order.h"
 #include "orders.h"
-
-#include <unistd.h>
-#include <fcntl.h>
-#include <time.h>
 
 #define	BUNGIE_NET_ORDER_DB_SIGNATURE		'ORDR'
 #define	UNUSED_ORDER_ID						0xFFFFFFFF
