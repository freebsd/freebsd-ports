--- src/specimen.c.orig	Mon Mar 12 01:32:12 2007
+++ src/specimen.c	Tue May 22 20:43:41 2007
@@ -73,7 +73,6 @@
      }
 
      /* start */
-     midi_start();
      driver_start(0, client_name);
 #ifdef HAVE_LASH
      lashdriver_start();
@@ -81,7 +80,6 @@
      gtk_main();
 
      /* stop */
-     midi_stop();
      driver_stop();
 
      /* destructors */
