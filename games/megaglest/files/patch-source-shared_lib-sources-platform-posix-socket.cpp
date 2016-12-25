--- source/shared_lib/sources/platform/posix/socket.cpp.orig	2016-12-26 00:02:43.325573000 +0100
+++ source/shared_lib/sources/platform/posix/socket.cpp	2016-12-26 00:04:06.681172000 +0100
@@ -2632,7 +2632,7 @@
 
 				//printf("UPnP device found: [%s] [%s] lanaddr [%s]\n", dev->descURL, dev->st,lanaddr);
 #if (defined(MINIUPNPC_API_VERSION)  && MINIUPNPC_API_VERSION >= 9) || (!defined(MINIUPNPC_VERSION_PRE1_7) && !defined(MINIUPNPC_VERSION_PRE1_6))
-				char *descXML = (char *)miniwget_getaddr(dev->descURL, &descXMLsize, lanaddr, (sizeof(lanaddr) / sizeof(lanaddr[0])),0);
+				char *descXML = (char *)miniwget_getaddr(dev->descURL, &descXMLsize, lanaddr, (sizeof(lanaddr) / sizeof(lanaddr[0])),0,0);
 #else
 				char *descXML = (char *)miniwget_getaddr(dev->descURL, &descXMLsize, lanaddr, (sizeof(lanaddr) / sizeof(lanaddr[0])));
 #endif
