--- src/hardware/lascar-el-usb/protocol.c.orig	2017-06-12 01:07:28 UTC
+++ src/hardware/lascar-el-usb/protocol.c
@@ -508,8 +508,7 @@ SR_PRIV int lascar_el_usb_handle_events(int fd, int re
 	}
 
 	memset(&tv, 0, sizeof(struct timeval));
-	libusb_handle_events_timeout_completed(drvc->sr_ctx->libusb_ctx, &tv,
-					       NULL);
+	libusb_handle_events_timeout(drvc->sr_ctx->libusb_ctx, &tv);
 
 	return TRUE;
 }
