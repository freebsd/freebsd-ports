--- src/anjuta_dirs.c.orig	Sat Mar 31 18:41:13 2001
+++ src/anjuta_dirs.c	Sat Mar 31 18:46:47 2001
@@ -36,11 +36,11 @@
    {
       sharedir    = g_dirname(PACKAGE_LOCALE_DIR);
       ad->tmp = g_strdup(g_get_tmp_dir());
-      ad->datadir = g_strconcat(sharedir, "/anjuta", NULL);
+      ad->datadir = g_strconcat(sharedir, "/gnome/anjuta", NULL);
       ad->data         = g_strdup(ad->datadir);
       ad->templetes = g_strdup(ad->datadir);
-      ad->pixmaps   = g_strconcat(ad->datadir, "/pixmaps", NULL);
-      /* ad->help   = g_strconcat(ad->datadir, "/help", NULL); */
+      ad->pixmaps   = g_strconcat(sharedir, "/gnome/pixmaps", NULL);
+      /* ad->help   = g_strconcat(sharedir, "/gnome/help", NULL); */
       ad->doc           = g_strconcat(sharedir, "/doc/anjuta", NULL);
       ad->home       = g_strdup(g_get_home_dir());
       ad->settings    = g_strconcat(ad->home, "/.anjuta",NULL);
