--- src/support/widgets/gtkxine.c.orig	2003-01-03 23:48:21.000000000 +0100
+++ src/support/widgets/gtkxine.c	2009-04-19 13:58:56.000000000 +0200
@@ -632,7 +632,7 @@
      */
     if (this->vo_driver != NULL)
 	xine_close_video_driver (this->xine, this->vo_driver);
-    if (this->vo_driver != NULL)
+    if (this->ao_driver != NULL)
 	xine_close_audio_driver (this->xine, this->ao_driver);
 
     /*
