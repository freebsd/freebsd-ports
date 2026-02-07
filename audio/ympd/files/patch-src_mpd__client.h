--- src/mpd_client.h.orig	2016-02-13 21:01:52 UTC
+++ src/mpd_client.h
@@ -92,12 +92,14 @@ struct t_mpd {
 
     int song_id;
     unsigned queue_version;
-} mpd;
+};
 
 struct t_mpd_client_session {
     int song_id;
     unsigned queue_version;
 };
+
+extern struct t_mpd mpd;
 
 void mpd_poll(struct mg_server *s);
 int callback_mpd(struct mg_connection *c);
