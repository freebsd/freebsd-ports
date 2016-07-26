--- src/specimen.c.orig	2007-03-12 00:32:12 UTC
+++ src/specimen.c
@@ -73,7 +73,6 @@ int main(int argc, char *argv[])
      }
 
      /* start */
-     midi_start();
      driver_start(0, client_name);
 #ifdef HAVE_LASH
      lashdriver_start();
@@ -81,7 +80,6 @@ int main(int argc, char *argv[])
      gtk_main();
 
      /* stop */
-     midi_stop();
      driver_stop();
 
      /* destructors */
