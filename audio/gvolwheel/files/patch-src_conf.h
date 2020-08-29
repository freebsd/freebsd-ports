--- src/conf.h.orig	2011-06-04 18:20:10 UTC
+++ src/conf.h
@@ -4,11 +4,11 @@
 #define OPT_CHANNEL_MASTER	0
 #define OPT_CHANNEL_PCM		1 
 
-gchar opt_mixer[100];
-guint opt_channel;
-guint opt_incr;
-gboolean opt_gnome_icons;
-gboolean opt_show_tooltip;
+extern gchar opt_mixer[100];
+extern guint opt_channel;
+extern guint opt_incr;
+extern gboolean opt_gnome_icons;
+extern gboolean opt_show_tooltip;
 
 void load_config();
 void save_config();
\ No newline at end of file
