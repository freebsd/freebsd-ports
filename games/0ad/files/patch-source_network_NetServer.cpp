--- source/network/NetServer.cpp.orig	2015-01-24 14:46:52 UTC
+++ source/network/NetServer.cpp
@@ -228,6 +228,7 @@ void* CNetServerWorker::SetupUPnP(void*)
 
 	int ret = 0;
 	bool allocatedUrls = false;
+	int	error	=	0; // Set this for upnpDiscover
 
 	// Try a cached URL first
 	if (!rootDescURL.empty() && UPNP_GetIGDFromUrl(rootDescURL.c_str(), &urls, &data, internalIPAddress, sizeof(internalIPAddress)))
@@ -236,7 +237,7 @@ void* CNetServerWorker::SetupUPnP(void*)
 		ret = 1;
 	}
 	// No cached URL, or it did not respond. Try getting a valid UPnP device for 10 seconds.
-	else if ((devlist = upnpDiscover(10000, 0, 0, 0, 0, 0)) != NULL)
+	else if ((devlist = upnpDiscover(10000, 0, 0, 0, 0, 0,&error)) != NULL)
 	{
 		ret = UPNP_GetValidIGD(devlist, &urls, &data, internalIPAddress, sizeof(internalIPAddress));
 		allocatedUrls = ret != 0; // urls is allocated on non-zero return values
