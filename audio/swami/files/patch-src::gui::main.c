--- src/gui/main.c.orig	Fri Jun 25 17:40:49 2004
+++ src/gui/main.c	Fri Jun 25 17:41:12 2004
@@ -119,6 +119,9 @@
 
   poptFreeContext (popt_ctx);
 
+  /* keep sound alive */
+  gtk_timeout_add(10, gtk_true, NULL);
+
   gdk_threads_enter ();
   gtk_main ();			/* kick it in the main GTK loop */
   gdk_threads_leave ();
