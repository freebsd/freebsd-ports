--- server/gam_server.c.orig	2007-07-04 09:36:49.000000000 -0400
+++ server/gam_server.c	2009-05-01 20:25:41.000000000 -0400
@@ -32,7 +32,7 @@
 #include "gam_server.h"
 #include "gam_channel.h"
 #include "gam_subscription.h"
-#include "gam_poll_generic.h"
+#include "gam_poll_basic.h"
 #ifdef ENABLE_INOTIFY
 #include "gam_inotify.h"
 #endif
@@ -200,7 +200,8 @@ gam_add_subscription(GamSubscription * s
 			return gam_poll_add_subscription (sub);
 		else
 #endif
-			return gam_kernel_add_subscription (sub);
+			/*return gam_kernel_add_subscription (sub);*/
+			return gam_poll_add_subscription (sub);
 	} else {
 		gam_fs_mon_type type;
 		type = gam_fs_get_mon_type (path);
@@ -243,7 +244,8 @@ gam_remove_subscription(GamSubscription 
 			return gam_poll_remove_subscription (sub);
 		else
 #endif
-			return gam_kernel_remove_subscription(sub);
+			/*return gam_kernel_remove_subscription(sub);*/
+			return gam_poll_remove_subscription (sub);
 	} else {
 		gam_fs_mon_type type;
 		type = gam_fs_get_mon_type (path);
@@ -438,7 +440,7 @@ gam_server_get_kernel_handler (void)
 GamPollHandler
 gam_server_get_poll_handler (void)
 {
-	return __gam_kernel_handler;
+	return __gam_poll_handler;
 }
 
 gboolean
