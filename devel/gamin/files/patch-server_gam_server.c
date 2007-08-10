--- server/gam_server.c.orig	2007-07-04 09:36:49.000000000 -0400
+++ server/gam_server.c	2007-08-10 15:09:14.000000000 -0400
@@ -32,7 +32,7 @@
 #include "gam_server.h"
 #include "gam_channel.h"
 #include "gam_subscription.h"
-#include "gam_poll_generic.h"
+#include "gam_poll_basic.h"
 #ifdef ENABLE_INOTIFY
 #include "gam_inotify.h"
 #endif
@@ -438,7 +438,7 @@ gam_server_get_kernel_handler (void)
 GamPollHandler
 gam_server_get_poll_handler (void)
 {
-	return __gam_kernel_handler;
+	return __gam_poll_handler;
 }
 
 gboolean
