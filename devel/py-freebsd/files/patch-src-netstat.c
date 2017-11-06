--- src/netstat.c.orig	2005-05-08 06:55:00 UTC
+++ src/netstat.c
@@ -243,7 +243,6 @@ PyFB_ifstats(PyObject *self)
 		Py_DECREF(t);
 		p_int(type);        p_int(physical);
 		p_int(addrlen);     p_int(hdrlen);
-		p_int(recvquota);   p_int(xmitquota);
 		p_long(mtu);        p_long(metric);
 		p_long(baudrate);   p_long(ipackets);
 		p_long(ierrors);    p_long(opackets);
