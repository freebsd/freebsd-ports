--- common/game_search_packets.c.orig	Wed Jan  7 16:16:05 2004
+++ common/game_search_packets.c	Wed Jan  7 16:18:38 2004
@@ -3,6 +3,9 @@
 Copyright (c) 1997-2002 Bungie Studios
 Refer to the file "License.txt" for details
 */
+#include <string.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 
 #include "cseries.h"
 #include "byte_swapping.h"
