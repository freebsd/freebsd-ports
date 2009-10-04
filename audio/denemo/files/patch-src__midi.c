--- src/midi.c.orig	2009-08-24 03:03:26.000000000 +0900
+++ src/midi.c	2009-09-28 17:25:00.000000000 +0900
@@ -384,7 +384,7 @@
   if(channel)
     g_io_channel_shutdown(channel, FALSE, &error);
   if(error)
-    g_warning(error->message);
+    g_warning("%s", error->message);
   else
     channel = NULL;
 #endif
