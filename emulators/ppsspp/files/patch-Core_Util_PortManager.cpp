--- Core/Util/PortManager.cpp.orig	2024-02-04 13:08:02 UTC
+++ Core/Util/PortManager.cpp
@@ -161,7 +161,21 @@ bool PortManager::Initialize(const unsigned int timeou
 
 		// Get LAN IP address that connects to the router
 		char lanaddr[64] = "unset";
-		int status = UPNP_GetValidIGD(devlist, urls, datas, lanaddr, sizeof(lanaddr)); //possible "status" values, 0 = NO IGD found, 1 = A valid connected IGD has been found, 2 = A valid IGD has been found but it reported as not connected, 3 = an UPnP device has been found but was not recognized as an IGD
+/*
+possible "status" values:
+-1 = Internal error
+ 0 = NO IGD found
+ 1 = A valid connected IGD has been found
+ 2 = A valid connected IGD has been found but its IP address is reserved (non routable)
+ 3 = A valid IGD has been found but it reported as not connected
+ 4 = an UPnP device has been found but was not recognized as an IGD
+*/
+		int status =
+#if (MINIUPNPC_API_VERSION >= 18)
+			UPNP_GetValidIGD(devlist, urls, datas, lanaddr, sizeof(lanaddr), nullptr, 0);
+#else
+			UPNP_GetValidIGD(devlist, urls, datas, lanaddr, sizeof(lanaddr));
+#endif
 		m_lanip = std::string(lanaddr);
 		INFO_LOG(SCENET, "PortManager - Detected LAN IP: %s", m_lanip.c_str());
 
