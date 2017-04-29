--- lib/netplay/netplay.cpp.orig	2017-04-23 13:12:16 UTC
+++ lib/netplay/netplay.cpp
@@ -1783,7 +1783,7 @@ static void NETcheckPlayers(void)
 // We should not block here.
 bool NETrecvNet(NETQUEUE *queue, uint8_t *type)
 {
-	switch (upnp_status)
+	switch ((int)upnp_status)
 	{
 	case UPNP_ERROR_CONTROL_NOT_AVAILABLE:
 	case UPNP_ERROR_DEVICE_NOT_FOUND:
