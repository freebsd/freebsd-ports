--- room_new/server_code.c.orig	Thu Feb  7 11:56:30 2002
+++ room_new/server_code.c	Wed Jan  7 16:51:20 2004
@@ -8,6 +8,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
@@ -25,6 +26,7 @@
 #include "bungie_net_order.h"
 #include "users.h"
 #include "games.h"
+#include "games_log.h"
 #include "rank.h"
 #include "metaserver_packets.h"
 #include "room_packets.h"
