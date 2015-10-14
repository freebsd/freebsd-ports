--- source/shared_lib/sources/platform/posix/socket.cpp.orig	2015-10-14 18:18:16 UTC
+++ source/shared_lib/sources/platform/posix/socket.cpp
@@ -2554,7 +2554,11 @@ int UPNP_Tools::upnp_init(void *param) {
 		int upnp_error = 0;
 
 #ifndef MINIUPNPC_VERSION_PRE1_6
+#if MINIUPNPC_API_VERSION >= 14
+		devlist = upnpDiscover(upnp_delay, upnp_multicastif, upnp_minissdpdsock, upnp_sameport, upnp_ipv6, 2, &upnp_error);
+#else
 		devlist = upnpDiscover(upnp_delay, upnp_multicastif, upnp_minissdpdsock, upnp_sameport, upnp_ipv6, &upnp_error);
+#endif
 
 		if(SystemFlags::getSystemSettingType(SystemFlags::debugNetwork).enabled) SystemFlags::OutputDebug(SystemFlags::debugNetwork,"UPnP discover returned upnp_error = %d.\n",upnp_error);
 		if(SystemFlags::VERBOSE_MODE_ENABLED) printf("UPnP discover returned upnp_error = %d.\n",upnp_error);
