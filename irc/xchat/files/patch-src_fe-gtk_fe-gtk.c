--- src/fe-gtk/fe-gtk.c.orig	2008-03-07 13:04:07.000000000 -0600
+++ src/fe-gtk/fe-gtk.c	2008-03-07 13:05:24.000000000 -0600
@@ -660,7 +660,7 @@
 	session *sess;
 	gdouble per;
 	char lagtext[64];
-	char lagtip[64];
+	char lagtip[128];
 	unsigned long nowtim;
 
 	if (lag == -1)
@@ -716,8 +716,8 @@
 	GSList *list = sess_list;
 	struct session *sess;
 	float per;
-	char tbuf[64];
-	char tip[64];
+	char tbuf[96];
+	char tip[160];
 
 	per = (float) serv->sendq_len / 1024.0;
 	if (per > 1.0)
