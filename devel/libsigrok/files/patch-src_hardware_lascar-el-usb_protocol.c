--- src/hardware/lascar-el-usb/protocol.c.orig	2019-12-25 20:29:19 UTC
+++ src/hardware/lascar-el-usb/protocol.c
@@ -513,8 +513,7 @@ SR_PRIV int lascar_el_usb_handle_events(int fd, int re
 	}
 
 	memset(&tv, 0, sizeof(struct timeval));
-	libusb_handle_events_timeout_completed(drvc->sr_ctx->libusb_ctx, &tv,
-					       NULL);
+	libusb_handle_events_timeout(drvc->sr_ctx->libusb_ctx, &tv);
 
 	return TRUE;
 }
