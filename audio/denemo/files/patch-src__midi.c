--- ./src/midi.c.orig	2010-04-06 23:54:58.000000000 -0400
+++ ./src/midi.c	2010-04-06 23:56:14.000000000 -0400
@@ -370,7 +370,7 @@
     if(channel)
       g_io_channel_shutdown(channel, FALSE, &error);
     if(error)
-      g_warning(error->message);
+      g_warning("%s", error->message);
     else
       channel = NULL;
     return 0;
