--- src/eb.c.orig	2007-12-28 00:09:02.000000000 +0900
+++ src/eb.c	2007-12-28 00:22:34.000000000 +0900
@@ -48,7 +48,6 @@
 static GtkWidget *label_match;
 static GtkWidget *progress;
 static pthread_t tid;
-static gint tag_timeout;
 static gint thread_running = 0;
 static gint hit_count=0;
 static gfloat search_progress;
