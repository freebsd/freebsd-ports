--- src/librnd/plugins/hid_remote/remote.c.orig	2022-12-04 07:06:55 UTC
+++ src/librnd/plugins/hid_remote/remote.c
@@ -392,7 +392,7 @@ int pplg_init_hid_remote(void)
 
 	rnd_hid_register_hid(&remote_hid);
 
-	rnd_event_bind(RND_EVENT_SET_CURRENT, ev_board_changed, NULL, remote_cookie);
+	rnd_event_bind(RND_EVENT_DESIGN_SET_CURRENT, ev_board_changed, NULL, remote_cookie);
 
 	return 0;
 }
