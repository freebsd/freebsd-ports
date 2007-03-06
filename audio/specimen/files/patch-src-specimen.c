--- src/specimen.c.orig	Tue Mar  6 13:10:22 2007
+++ src/specimen.c	Tue Mar  6 13:10:29 2007
@@ -48,14 +48,12 @@
      }
      
      /* start */
-     midi_start();
      driver_start(0, forced_instance_name);
      lashdriver_start();
 
      gtk_main();
 
      /* stop */
-     midi_stop();
      driver_stop();
 
      /* destructors */
