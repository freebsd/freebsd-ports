--- cddbslave/cddbsubmit.c.orig	Tue Apr 16 15:53:12 2002
+++ cddbslave/cddbsubmit.c	Tue Apr 16 15:53:20 2002
@@ -210,7 +210,7 @@
   poptFreeContext(gnomelib_parse_args(argc, argv, 0));
 
   /* config prefix points to cddb submission description file */
-  fname = gnome_datadir_file("gnome/cddb-submit-methods");
+  fname = gnome_datadir_file("cddb-submit-methods");
   prefix = g_strconcat("=", fname, "=/", service, "/", NULL);
   g_free(fname);
   gnome_config_push_prefix(prefix);
