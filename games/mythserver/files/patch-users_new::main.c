--- users_new/main.c.orig	Thu Feb  7 11:58:56 2002
+++ users_new/main.c	Wed Jan  7 17:13:02 2004
@@ -6,7 +6,6 @@
 
 #define SERVER
 
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
@@ -97,16 +97,7 @@
 	NUMBER_OF_CLIENT_TYPES
 };
 
-#define CLIENT_DATA_HEADER \
-	int socket; \
-	long host; \
-	short port; \
-	short type; \
-	char buffer[MAXIMUM_PACKET_LENGTH]; \
-	short state; \
-	void *next; \
-	struct circular_queue incoming; \
-	struct circular_queue outgoing;
+#define CLIENT_DATA_HEADER int socket; long host; short port; short type; char buffer[MAXIMUM_PACKET_LENGTH]; short state; void *next; struct circular_queue incoming; struct circular_queue outgoing;
 
 struct client_data {
 	CLIENT_DATA_HEADER
