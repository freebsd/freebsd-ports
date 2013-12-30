--- ./hardware/lascar-el-usb/protocol.c.orig	2013-06-22 17:57:14.000000000 +0200
+++ ./hardware/lascar-el-usb/protocol.c	2013-06-22 17:57:56.000000000 +0200
@@ -512,8 +512,7 @@
 	}
 
 	memset(&tv, 0, sizeof(struct timeval));
-	libusb_handle_events_timeout_completed(drvc->sr_ctx->libusb_ctx, &tv,
-					       NULL);
+	libusb_handle_events_timeout(drvc->sr_ctx->libusb_ctx, &tv);
 
 	return TRUE;
 }
