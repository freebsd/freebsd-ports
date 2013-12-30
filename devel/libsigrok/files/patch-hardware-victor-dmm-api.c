--- ./hardware/victor-dmm/api.c.orig	2013-06-22 17:57:10.000000000 +0200
+++ ./hardware/victor-dmm/api.c	2013-06-22 17:57:36.000000000 +0200
@@ -379,8 +379,7 @@
 	}
 
 	memset(&tv, 0, sizeof(struct timeval));
-	libusb_handle_events_timeout_completed(drvc->sr_ctx->libusb_ctx, &tv,
-					       NULL);
+	libusb_handle_events_timeout(drvc->sr_ctx->libusb_ctx, &tv);
 
 	return TRUE;
 }
