--- src/network/C4Network2UPnPLinux.cpp.orig	2018-03-16 17:25:33 UTC
+++ src/network/C4Network2UPnPLinux.cpp
@@ -77,7 +77,11 @@ void C4Network2UPnPP::Init()
 	if ((devlist = upnpDiscover(2000, nullptr, nullptr, UPNP_LOCAL_PORT_ANY, 0, 2, &error)))
 #endif
 	{
+#if MINIUPNPC_API_VERSION >= 18
+		if ((status = UPNP_GetValidIGD(devlist, &upnp_urls, &igd_data, lanaddr, sizeof(lanaddr), NULL, 0)))
+#else
 		if ((status = UPNP_GetValidIGD(devlist, &upnp_urls, &igd_data, lanaddr, sizeof(lanaddr))))
+#endif
 		{
 			ThreadLogS("UPnP: Found IGD %s (status %d)", upnp_urls.controlURL, status);
 			initialized = true;
