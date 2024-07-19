--- src/upnp.c.orig	2020-02-09 21:48:57 UTC
+++ src/upnp.c
@@ -134,8 +134,13 @@ int upnp_handler(struct upnp_handle_t *handle, uint16_
 			handle->retry = now + (10 * 60);
 			handle->state = UPNP_STATE_DISCOVER_GATEWAY;
 			return PF_RETRY;
+#if (MINIUPNPC_API_VERSION >= 18)
 		} else if (UPNP_GetValidIGD(devlist, &handle->urls, &handle->data,
+				handle->addr, sizeof(handle->addr), NULL, 0) == 1) {
+#else
+		} else if (UPNP_GetValidIGD(devlist, &handle->urls, &handle->data,
 				handle->addr, sizeof(handle->addr)) == 1) {
+#endif                  
 			freeUPNPDevlist(devlist);
 			log_info("UPnP: Found gateway device \"%s\".", handle->urls.controlURL);
 			handle->state = UPNP_STATE_GET_PORTMAPPING;
