--- src/upnp.c.orig	2013-02-13 21:06:15.000000000 +0100
+++ src/upnp.c	2016-12-25 23:05:37.702936000 +0100
@@ -60,11 +60,15 @@
 	tostdout_write();
 	memset(&urls, 0, sizeof(struct UPNPUrls));
 	memset(&data, 0, sizeof(struct IGDdatas));
+#if MINIUPNPC_API_VERSION >= 14
+	devlist = upnpDiscover(2000, NULL, NULL, 0, 0, 2U, NULL);
+#else
 #ifdef UPNPDISCOVER_SUCCESS
 	devlist = upnpDiscover(2000, NULL, NULL, 0, 0, NULL);
 #else
 	devlist = upnpDiscover(2000, NULL, NULL, 0);
 #endif /* UPNPDISCOVER_SUCCESS */
+#endif
 	if (devlist)
 	{
 		dev = devlist;
@@ -81,11 +85,15 @@
 			"UPnP device : desc: %s\n st: %s",
 			dev->descURL, dev->st);
 
+#if MINIUPNPC_API_VERSION >= 16
+		descXML = miniwget(dev->descURL, &descXMLsize, 0, 0);
+#else
 #if MINIUPNPC_API_VERSION >= 9
 		descXML = miniwget(dev->descURL, &descXMLsize, 0);
 #else
 		descXML = miniwget(dev->descURL, &descXMLsize);
 #endif
+#endif
 		if (descXML)
 		{
 			parserootdesc (descXML, descXMLsize, &data);
