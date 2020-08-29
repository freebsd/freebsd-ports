--- src/main.c.orig	2012-04-07 21:54:38 UTC
+++ src/main.c
@@ -71,7 +71,11 @@ static GOptionEntry entries[] =
 	{NULL}
 };
 
-
+gchar opt_mixer[100];
+guint opt_channel;
+guint opt_incr;
+gboolean opt_gnome_icons;
+gboolean opt_show_tooltip;
 
 int main (int argc, char *argv[])
 {
