--- snd_sdl.c.orig	Sun Mar 14 17:59:19 2004
+++ snd_sdl.c	Sun Mar 14 17:59:35 2004
@@ -119,3 +119,12 @@
 	}
 }
 
+/*
+==============
+SNDDMA_Submit
+Send sound to device if buffer isn't really the dma buffer
+===============
+*/
+void SNDDMA_Submit(void)
+{
+}
