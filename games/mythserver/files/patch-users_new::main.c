--- users_new/main.c.orig	Sun May 18 02:36:43 2003
+++ users_new/main.c	Sun May 18 02:37:47 2003
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
