--- src/decoder.c.orig	Mon Jun 23 21:25:14 2003
+++ src/decoder.c	Mon Jun 23 21:25:27 2003
@@ -4,6 +4,7 @@
 #endif
 
 #include <gnome.h>
+#include <pthread.h>
 #include "liteamp.h"
 #include "decoder.h"
 #include "playback.h"
@@ -266,7 +267,7 @@
         queue_data *data = g_malloc0(sizeof(queue_data));
         data->command = g_strdup("EXIT");
         g_async_queue_push(queue,(gpointer)data);
-        pthread_join(tid);
+        pthread_join(tid, NULL);
     }
 }
 
