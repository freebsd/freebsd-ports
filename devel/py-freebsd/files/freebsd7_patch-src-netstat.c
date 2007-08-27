--- src/netstat.c.orig	2007-08-17 13:07:10.654911645 -0500
+++ src/netstat.c	2007-08-17 13:07:19.496912514 -0500
@@ -243,7 +243,6 @@
 		Py_DECREF(t);
 		p_int(type);        p_int(physical);
 		p_int(addrlen);     p_int(hdrlen);
-		p_int(recvquota);   p_int(xmitquota);
 		p_long(mtu);        p_long(metric);
 		p_long(baudrate);   p_long(ipackets);
 		p_long(ierrors);    p_long(opackets);
