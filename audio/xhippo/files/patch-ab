--- xhippo.c.orig	Wed Jun  6 09:03:19 2001
+++ xhippo.c	Wed Jun  6 09:05:04 2001
@@ -611,13 +611,14 @@
 
   /* Deal with non-options */
   while (optind < argc) {
-    if (mode_commandline_songs) {
+    if (mode_commandline_songs)
       add_file(argv[optind++]);
-    } else if (mode_commandline_dirs) {
-      add_directory(argv[optind++]);
-    } else {
+    else
       read_playlist(argv[optind++]);
-    }
+#ifdef HAVE_NFTW 
+   if (mode_commandline_dirs)
+      add_directory(argv[optind++]);
+#endif
   }
   
   /* Show the list and scrollbar. */
