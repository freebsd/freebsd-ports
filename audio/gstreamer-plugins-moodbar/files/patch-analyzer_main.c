--- analyzer/main.c.orig	2006-10-12 05:43:30 UTC
+++ analyzer/main.c
@@ -261,7 +261,7 @@ main (gint argc, gchar *argv[])
     };
   GOptionContext *ctx;
   GError *err = NULL;
-
+  g_thread_init(NULL);
   ctx = g_option_context_new ("[INFILE] - Run moodbar analyzer");
   g_option_context_add_group (ctx, gst_init_get_option_group ());
   g_option_context_add_main_entries (ctx, entries, NULL);
