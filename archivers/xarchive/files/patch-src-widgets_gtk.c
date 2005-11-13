--- src/widgets_gtk.c.orig	Tue Nov  8 20:39:01 2005
+++ src/widgets_gtk.c	Sun Nov 13 03:03:53 2005
@@ -1022,8 +1022,9 @@
 
   if (wrapper_cmd(AR_EXTRACT, wrapper->argv, wrapper->dir) == 0)
   {
+    gchar *viewcmd;
     fname = my_strescape(wrapper->argv[FIRST_FILE_INDEX]);
-    gchar *viewcmd = g_strconcat(command, " ", wrapper->dir,
+    viewcmd = g_strconcat(command, " ", wrapper->dir,
                                  "/", fname, NULL);
     g_free(fname);
     printf("viewcmd: %s\n",viewcmd);
