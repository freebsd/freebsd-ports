--- src/widgets_gtk.c.orig	2006-02-27 14:00:30 UTC
+++ src/widgets_gtk.c
@@ -1131,8 +1131,9 @@ open_one_file(WrapperData *wrapper, gcha
 
   if (wrapper_cmd(AR_EXTRACT, wrapper->argv, wrapper->dir) == 0)
   {
+    gchar *viewcmd;
     fname = my_strescape(wrapper->argv[FIRST_FILE_INDEX]);
-    gchar *viewcmd = g_strconcat(command, " ", wrapper->dir,
+    viewcmd = g_strconcat(command, " ", wrapper->dir,
                                  "/", fname, NULL);
     g_free(fname);
     printf("viewcmd: %s\n",viewcmd);
