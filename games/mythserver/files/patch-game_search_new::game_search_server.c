--- game_search_new/game_search_server.c.orig	Thu Feb  7 11:56:08 2002
+++ game_search_new/game_search_server.c	Wed Jan  7 16:39:16 2004
@@ -3,6 +3,16 @@
 Copyright (c) 1997-2002 Bungie Studios
 Refer to the file "License.txt" for details
 */
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <sys/time.h>
+#include <sys/ioctl.h>
+#include <arpa/inet.h>
+#include <signal.h>
+#include <fcntl.h>
+#include <string.h>
+#include <unistd.h>
 
 #include "cseries.h"
 #include "metaserver_common_structs.h"
@@ -19,13 +29,6 @@
 #include "network_queues.h"
 #include "game_search_packets.h"
 #include "games_list.h"
-
-#include <sys/socket.h>
-#include <sys/time.h>
-#include <sys/ioctl.h>
-#include <arpa/inet.h>
-#include <signal.h>
-#include <fcntl.h>
 
 #define	MAXIMUM_OUTSTANDING_REQUESTS	32
 #define	SELECT_TIMEOUT_PERIOD		10
