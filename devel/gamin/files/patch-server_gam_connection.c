--- server/gam_connection.c.orig	Wed Jul 13 17:54:01 2005
+++ server/gam_connection.c	Wed Jul 13 17:54:54 2005
@@ -30,10 +30,7 @@
     GMainLoop *loop;            /* the Glib loop used */
     GIOChannel *source;         /* the Glib I/O Channel used */
     int request_len;            /* how many bytes of request are valid */
-    union {
-	GAMPacket request;      /* the next request being read */
-	void *request_data;     /* the next request as a char *  */
-    };
+    GAMPacket request;          /* the next request being read */
     GamListener *listener;      /* the listener associated with the connection */
 };
 
@@ -245,7 +242,7 @@
     g_assert(data);
     g_assert(size);
 
-    *data = (char *) &conn->request_data + conn->request_len;
+    *data = (char *) &conn->request + conn->request_len;
     *size = sizeof(GAMPacket) - conn->request_len;
 
     return (0);
