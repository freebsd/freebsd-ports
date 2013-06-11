--- source/shared_lib/sources/platform/posix/socket.cpp.orig	2013-05-15 21:33:42.000000000 -0500
+++ source/shared_lib/sources/platform/posix/socket.cpp	2013-05-15 21:37:06.000000000 -0500
@@ -2478,13 +2478,22 @@
 				if(SystemFlags::VERBOSE_MODE_ENABLED) printf("UPnP device found: %s %s\n", dev->descURL, dev->st);
 
 				//printf("UPnP device found: [%s] [%s] lanaddr [%s]\n", dev->descURL, dev->st,lanaddr);
+#ifndef MINIUPNPC_VERSION_PRE1_7
+				descXML = (char *)miniwget_getaddr(dev->descURL, &descXMLsize, lanaddr, (sizeof(lanaddr) / sizeof(lanaddr[0])),0);
+#else
 				descXML = (char *)miniwget_getaddr(dev->descURL, &descXMLsize, lanaddr, (sizeof(lanaddr) / sizeof(lanaddr[0])));
+#endif
 				if(SystemFlags::getSystemSettingType(SystemFlags::debugNetwork).enabled) SystemFlags::OutputDebug(SystemFlags::debugNetwork,"LAN address: %s\n", lanaddr);
 
 				if (descXML) {
 					parserootdesc (descXML, descXMLsize, &data);
 					free (descXML); descXML = 0;
+
+#ifndef MINIUPNPC_VERSION_PRE1_7
+					GetUPNPUrls (&urls, &data, dev->descURL,0);
+#else
 					GetUPNPUrls (&urls, &data, dev->descURL);
+#endif
 				}
 				snprintf(buf, 255,"UPnP device found: %s %s LAN address %s", dev->descURL, dev->st, lanaddr);
 
