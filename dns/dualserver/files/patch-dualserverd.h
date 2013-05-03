--- dualserverd.h	2013-04-21 03:13:15.000000000 +0200
+++ dualserverd.h	2013-04-27 18:55:24.000000000 +0200
@@ -614,10 +614,19 @@
 
 struct msg_control
 {
+#ifdef __FreeBSD__
+  u_long cmsg_len;
+#else
 	ulong cmsg_len;
+#endif
 	int cmsg_level;
 	int cmsg_type;
+#ifdef __FreeBSD__
+  // Arbitrary size, when the size is required we use sizeof
+  unsigned char pktinfo[100];
+#else
 	in_pktinfo pktinfo;
+#endif
 };
 
 #if defined(__hppa__) || \
@@ -735,7 +744,11 @@
 	union
 	{
 		int broadCastVal;
+#ifdef __FreeBSD__
+    int pktinfoVal;
+#else
 		bool pktinfoVal;
+#endif
 	};
 	union
 	{
