--- src/mpd_client.c.orig	2020-08-28 21:21:59 UTC
+++ src/mpd_client.c
@@ -27,6 +27,8 @@
 #include "config.h"
 #include "json_encode.h"
 
+struct t_mpd mpd;
+
 /* forward declaration */
 static int mpd_notify_callback(struct mg_connection *c, enum mg_event ev);
 
