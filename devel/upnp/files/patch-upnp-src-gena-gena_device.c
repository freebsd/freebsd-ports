--- upnp/src/gena/gena_device.c.orig
+++ upnp/src/gena/gena_device.c
@@ -225,7 +225,7 @@ static UPNP_INLINE int notify_send_and_r
 		"bbb",
 		start_msg.buf, start_msg.length,
 		propertySet, strlen(propertySet),
-		"\r\n", 2);
+		"\r\n", sizeof "\r\n" - 1);
 	if (ret_code) {
 		membuffer_destroy(&start_msg);
 		sock_destroy(&info, SD_BOTH);
