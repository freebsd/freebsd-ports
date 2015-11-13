Index: src/upnp.c
===================================================================
RCS file: /usr/home/public/iroffer/src/upnp.c,v
retrieving revision 1.15
retrieving revision 1.17
diff -u -r1.15 -r1.17
--- src/upnp.c	13 Feb 2013 20:06:15 -0000	1.15
+++ src/upnp.c	13 Oct 2015 18:30:24 -0000	1.17
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
