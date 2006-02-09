--- server/gam_server.c.orig	Wed Sep 21 18:21:05 2005
+++ server/gam_server.c	Tue Feb  7 13:12:02 2006
@@ -32,7 +32,7 @@
 #include "gam_server.h"
 #include "gam_channel.h"
 #include "gam_subscription.h"
-#include "gam_poll_generic.h"
+#include "gam_poll_basic.h"
 #ifdef ENABLE_INOTIFY
 #include "gam_inotify.h"
 #endif
@@ -164,7 +164,7 @@
 #endif	
 	}
 
-	if (gam_poll_generic_init()) {
+	if (gam_poll_basic_init()) {
 		GAM_DEBUG(DEBUG_INFO, "Using poll as backend\n");
 		return(TRUE);
 	}
@@ -427,7 +427,7 @@
 GamPollHandler
 gam_server_get_poll_handler (void)
 {
-	return __gam_kernel_handler;
+	return __gam_poll_handler;
 }
 
 gboolean
